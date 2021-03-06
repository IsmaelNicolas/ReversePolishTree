/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file main.cpp
* @author Ismael Cedillo y Angel Castillo
* @date 2/3/2021
* @brief Programa principal
*/

#include "stack.cpp"
#include "postfix.h"
#include "Arbol.h"

//! evaluates postfix expression.
float eval_postfix(char* postfix){
    stack<string> operands; 
    istringstream stin;
    float evaluated;
    string character;	
    string expression(postfix); 
    stin.str(expression);
	Arbol bTree;	

    while(stin >> character){
        if(character == "+" || character == "-" || character == "*" || character == "/" || character == "^"){
		bTree.insertar(character);
            	compute(character, operands);
        }
        else{
		bTree.insertar(character);
            	operands.push(character);
        }
    }
    evaluated = atof(operands.topAndPop().c_str());
	bTree.inorder(bTree.getRaiz());
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

