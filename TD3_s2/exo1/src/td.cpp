#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <cctype>


//exo 1

// Fonction pour séparer les éléments de la chaîne en tokens
std::vector<std::string> split_string(std::string const& s) {
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

// Fonction pour vérifier si une chaîne de caractères représente un nombre flottant
bool is_floating(std::string const& s) {
    for (char c : s) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

// Fonction pour évaluer une expression en NPI
float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> stack;
    for (const std::string& token : tokens) {
        if (is_floating(token)) {
            stack.push(std::stof(token)); // Converti l chaîne en nbre flo et l'empile
        } else {
            float rightOperand = stack.top();
            stack.pop();
            float leftOperand = stack.top();
            stack.pop();
            float result;
            if (token == "+") {
                result = leftOperand + rightOperand;
            } else if (token == "-") {
                result = leftOperand - rightOperand;
            } else if (token == "*") {
                result = leftOperand * rightOperand;
            } else if (token == "/") {
                result = leftOperand / rightOperand;
            } // Ajoutez d'autres opérateurs si nécessaire
            stack.push(result);
        }
    }
    if (stack.size() != 1) {
        std::cout << "merci de donner une expression valid" << std::endl;
        return std::numeric_limits<float>::quiet_NaN(); // Retourne NotaNumber https://cplusplus.com/reference/cmath/nan-function/ pour indiquer une erreur
    }
    return stack.top(); // renvoie le resultat fina
}




int main() {
    std::string input;
    std::cout << "Entrez une expression NPI : ";
    std::getline(std::cin, input);

    std::vector<std::string> tokens = split_string(input);
    float result = npi_evaluate(tokens);

    if (!std::isnan(result)) {
        std::cout << "Le resultat de cette  ewpresion vaut : " << result << std::endl;
    }

    return 0;
}


