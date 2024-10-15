#include <iostream>
#include <string>
#include <map>
#include <cctype>

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
reservedToken getToken(const std::string& str)
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
}