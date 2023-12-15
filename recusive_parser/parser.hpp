#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
class Grammar;

typedef std::vector<std::string> Tokens; 
typedef std::shared_ptr<Grammar> GrammarT;
typedef std::pair<GrammarT, GrammarT> GrammarChildrenT;

enum class Terminality{
    TERMINAL    = 0,
    NONTERMINAL = 1
};
void InitGrammar();//Instantiate an instance of each grammar to global, once each token gets parsed, token -> type than process gets called on roots.

class Grammar{
public:
    Grammar() = default;
    std::int64_t recursion_depth =0;
    GrammarChildrenT children;
    //inherited by both terminal and non-terminals 
    virtual void process(const Tokens& tokens ){};
    virtual Terminality getTerminality(){
        static_assert("ERR: You are invoking getTerminality from an invalid obj, obj probably does not implement getTerminality!");
    };
    virtual std::string getGrammarName(){
        
        static_assert("ERR: You are invoking getGrammarName from an invalid obj, obj probably does not implement getTerminality!");

    }
    void createChildren(GrammarChildrenT g){
        if(this->getTerminality() == Terminality::NONTERMINAL){

            static_assert("ERR: Trying to add children to a terminal object!\n");
        }
    };

};

class TerminalGrammer:public Grammar{
    //terminal cannot be root! 
public:
    static const Terminality terminality = Terminality::TERMINAL;
    virtual Terminality getTerminality() override {
        return terminality;
    };
private:
};
class NonTerminalGrammar:public Grammar{
    //only NonTerminal can spawn childen!
public:
    //
    // NonTerminalGrammar() = default;
    // void process(const Tokens& tokens ){}
    static const Terminality terminality = Terminality::NONTERMINAL;
    Terminality getTerminality() override{
        return terminality;
    };
    virtual std::string getGrammarName() override{
        return "NonTerminal";
    }
    void process(const Tokens& tokens)override{

        for (auto x = 0; x < recursion_depth;){
            std::cout<<'-';
        }
        std::cout<<getGrammarName();
        std::cout<<this->recursion_depth<<"\n";
    }
    // void process(const Tokens& tokens );
    // void createChildren(GrammarChildrenT g);
  
private:
    //rootable -> children can be rootable/non roots
};
