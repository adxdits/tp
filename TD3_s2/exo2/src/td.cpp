#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <cctype>
#include <cmath>

// Enum
enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN };
enum class TokenType { OPERATOR, OPERAND };

// structure  token
struct Token {
    TokenType type;
    float value;
    Operator op;
};

// creation dun token à partir d'un flottant 
Token make_token(float value) {
    return {TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op) {
    return {TokenType::OPERATOR, 0.0f, op};
}

// fonction pour tokeniser 
std::vector<Token> tokenize(std::vector<std::string> const& words) {
    std::vector<Token> tokens;
    for (const std::string& word : words) {
        if (word == "+") {
            tokens.push_back(make_token(Operator::ADD));
        } else if (word == "-") {
            tokens.push_back(make_token(Operator::SUB));
        } else if (word == "*") {
            tokens.push_back(make_token(Operator::MUL));
        } else if (word == "/") {
            tokens.push_back(make_token(Operator::DIV));
        } else if (word == "(") {
            tokens.push_back(make_token(Operator::OPEN_PAREN));
        } else if (word == ")") {
            tokens.push_back(make_token(Operator::CLOSE_PAREN));
        } else {
            float value = std::stof(word);
            tokens.push_back(make_token(value));
        }
    }
    return tokens;
}

// Fonction pour évaluer une expression en NPI
float npi_evaluate(std::vector<Token> const& tokens) {
    std::stack<float> stack;
    for (const Token& token : tokens) {
        if (token.type == TokenType::OPERAND) {
            stack.push(token.value);
        } else {
            float rightOperand = stack.top();
            stack.pop();
            float leftOperand = stack.top();
            stack.pop();
            float result;
            if (token.op == Operator::ADD) {
                result = leftOperand + rightOperand;
            } else if (token.op == Operator::SUB) {
                result = leftOperand - rightOperand;
            } else if (token.op == Operator::MUL) {
                result = leftOperand * rightOperand;
            } else if (token.op == Operator::DIV) {
                result = leftOperand / rightOperand;
            }
            stack.push(result);
        }
    }
    return stack.top();
}

int main() {
    std::string input;
    std::cout << "Entre une expression NPI : ";
    std::getline(std::cin, input);

    // separation
    std::istringstream iss(input);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    // tokenisation
    std::vector<Token> tokens = tokenize(words);

    // evaluation en npi
    float result = npi_evaluate(tokens);

 // isnotanumber
    if (!std::isnan(result)) {  
        std::cout << "Le resultat vaut : " << result << std::endl;
    }

    return 0;
}