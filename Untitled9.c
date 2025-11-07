#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max_size 10
#define TableSize (max_size+1)
typedef struct{
	char op;
	int precedence;
	char associativity;
}Operator;
char get_precedence(Operator op1, Operator op2,Operator operators[],int num_operators ){
	    if(op1.op =='$' && op2.op=='$'){
	    	return 'A';
		}
	    if(op2.op=='$'){
	    	return '>';
		}
		if(op1.op=='$'){
			return '<';
		}
		if(op1.precedence>op2.precedence){
			return '>';
		}
		else if (op1.precedence < op2.precedence) {
            return '<';
        }         
		else{
			if (op1.associativity == 'L') {
            return '>';} 
		    else { 
            return '<';}
		}
}
Operator* findOperator(char symbol,Operator operators[],int num_operators){
	for(int i=0;i<num_operators;i++){
		if(operators[i].op==symbol){
			return &operators[i];
		}
	}
	if(symbol=='$'){
		static Operator dollar_op={'$',0,'L'};
		return &dollar_op;
	}
	return NULL;
}
int main(){
	Operator operators[max_size];
	int num_operators=0;
	operators[num_operators++]=(Operator){'+',1,'L'};
	operators[num_operators++]=(Operator){'-',1,'L'};
	operators[num_operators++]=(Operator){'*',2,'L'};
	operators[num_operators++]=(Operator){'/',2,'L'};
	operators[num_operators++]=(Operator){'^',3,'L'};
	operators[num_operators++]=(Operator){'(',4,'L'};
	operators[num_operators++]=(Operator){')',4,'L'};
	char terminals[TableSize];
	for(int i=0;i<num_operators;i++){
		terminals[i]=operators[i].op;
	}
	terminals[num_operators]='$';
	char precedence_table[TableSize][TableSize];
	for(int i=0;i<max_size;i++){
		for(int j=0;j<max_size;j++){
			 precedence_table[i][j]=' ';
		}
	}
	int num_terminals=num_operators+1;
	//fill table
	for(int i=0;i<num_operators+1;i++){
		for(int j=0;j<num_operators+1;j++){
			 Operator* op1 = findOperator(terminals[i], operators, num_operators);
             Operator* op2 = findOperator(terminals[j], operators, num_operators);
             if(op1!=NULL && op2!=NULL){
             	precedence_table[i][j]=get_precedence(*op1,*op2,operators,num_operators);
			 }
		}
    }
		printf("operator precedence table:\n   ");
		for(int i=0;i<num_terminals;i++){
			printf("%c  ",terminals[i]);
		}
		printf("\n");
		for(int i=0;i<num_terminals;i++){
			 printf("%c | ",terminals[i]);
			for(int j=0;j<num_terminals;j++){
				printf("%c  ",precedence_table[i][j]);
			}
			printf("\n");
		}
	return 0;
}
