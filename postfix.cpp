/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file main.cpp
* @author Ismael Cedillo y Angel Castillo
* @date 2/3/2021
* @brief Programa principal
*/

#include "stack.cpp"
#include "postfix.h"

//! evaluates postfix expression.
float eval_postfix(char* postfix){
    stack<string> operands; 
    istringstream stin;
    float evaluated;
    string character;	
    string expression(postfix); 
    stin.str(expression);

    while(stin >> character){
        if(character == "+" || character == "-" || character == "*" || character == "/" || character == "^"){
            compute(character, operands);
        }
        else{
            operands.push(character);
        }
    }
    evaluated = atof(operands.topAndPop().c_str());
    return evaluated;
}


//! computes binary operations for eval_postfix function.
void compute(string operation, stack<string>& operands){
    
    float first, second, solved;
    second = atof(operands.topAndPop().c_str());
    first = atof(operands.topAndPop().c_str());
    ostringstream output;
    string result;
    
    if(operation == "+"){
        solved = first + second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "-"){
        solved = first - second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "*"){
        solved = first * second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "/"){
        solved = first / second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "^"){
        solved = pow(first, second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
}

