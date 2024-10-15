#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector> 
#include <sstream>

// Create reserved tokens for the parser
enum reservedToken
{
    END,
    RETURN,
    WHILE,
    IF,
    VAR,
    IDENTIFIER,
    NUMCONST,
    STRINGCONST,
    OR,
    AND,
    EQ,
    NEQ,
    PP,
    MM,
    PL_EQ,
    MI_EQ,
    INVALID
};


// Map strings to tokens (for the keywords and operator)
reservedToken getToken(const std::string &str)
{
    std::map<std::string, reservedToken> keywordOperatorMap = {
        {"return", RETURN},
        {"while", WHILE},
        {"if", IF},
        {"var", VAR},
        {"||", OR},
        {"&&", AND},
        {"==", EQ},
        {"!=", NEQ},
        {"++", PP},
        {"--", MM},
        {"+=", PL_EQ},
        {"-=", MI_EQ}
    };

    // Verify if the following is not a token

    // Verify if the following keyword/operator
    if (keywordOperatorMap.find(str) != keywordOperatorMap.end()) 
    {   
        return keywordOperatorMap[str];
    }

    // Verify if the following is numeric
    if (std::isdigit(str[0]))
    {
        return NUMCONST;
    }

    // Verify if the following is an identifer
    if(std::isalpha(str[0]))
    {
        return IDENTIFIER;
    }

    // Otherwise, following input is invalid
    return INVALID;
}


// Vectorize and tokenize the input 
std::vector<std::string> tokenize(std::string &input)
{
    // Gather stream of char/strings via input
    std::stringstream stream (input);
    std::vector<std::string> tokens; std::string token;
    while(stream >> token)
        tokens.push_back(token);
    return tokens;
}


static void parse (std::string& input)
{
    auto tokens = tokenize(input);

    // Operate on different cases
    for(std::string &tokenizedString : tokens){
        reservedToken rToken = getToken(tokenizedString);
        
        // Different cases
        switch(rToken){
            case RETURN: 
                std::cout << "Return statement found, exit" << std::endl;
                break;
            case WHILE:
                std::cout << "While loop found, loop" << std::endl;
                break;
            case IF:
                std::cout << "If statement found, evaluate conditional" << std::endl;
                break;
            case VAR:
                std::cout << "Variable declaration made!" << std::endl;
                break;
            case NUMCONST:
                std::cout << "Number constant identified: " << rToken << std::endl;
                break;
            case IDENTIFIER:
                std::cout << "Identifier found: " << rToken << std::endl;
                break;
            case EQ:
                std::cout << "Logical equivalent found ==" << std::endl;
                break;
            case OR:
                std::cout << "Logical OR found ||" << std::endl;
                break;
            case AND:
                std::cout << "Logical AND found &&" << std::endl;
                break;
            case INVALID: // indicate failure
                default:
                    std::cout << "Invalid token: " << rToken << std::endl;
                    break;

        }
    }
}