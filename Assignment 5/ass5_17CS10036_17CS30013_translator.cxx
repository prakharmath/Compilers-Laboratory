#include "ass5_17CS10036_17CS30013_translator.h"
#include <bits/stdc++.h>
using namespace std;
#include "y.tab.h"

void Quad :: print()
{
	if(op >= PLUS && op <=GREATER_EQUAL)
	{
		if(result.compare("")==1)
			cout<<result<<" = "<<arg_1;
		else
			cout<<arg_1;
		switch(op)
		{
            case PLUS:
				cout<<"+";
				break;
            case MINUS:
				cout<<"-";
				break;
            case MULT:
				cout<<"*";
				break;
            case DIVIDE:
				cout<<"/";
				break;
			case AND:
				cout<<"&";
				break;
            case MODULO:
				cout<<"%";
				break;
            case SHIFT_LEFT:
				cout<<"<<";
				break;
            case SHIFT_RIGHT:
				cout<<">>";
				break;
            case XOR:
				cout<<"^";
				break;
            case OR:
				cout<<"|";
				break;
            case LOGICAL_AND:
				cout<<"&&";
				break;
            case LOGICAL_OR:
				cout<<"||";
				break;
            case LESS:
				cout<<"<";
				break;
            case GREATER:
				cout<<">";
				break;
            case IS_EQUAL:
				cout<<"==";
				break;
            case NOT_EQUAL:
				cout<<"!=";
				break;
            case LESS_EQUAL:
				cout<<"<=";
				break;
            case GREATER_EQUAL:
				cout<<">=";
				break;
		}
		cout<<arg_2<<"\n";
	}
	else if(op >= UNARY_PLUS && op <=NOT)
	{
		cout<<result<<" = ";
		switch(op)
		{
			case UNARY_PLUS:
				cout<<"+";
				break;
			case UNARY_MINUS:
				cout<<"-";
				break;
			case COMPLEMENT:
				cout<<"~";
				break;
			case NOT:
				cout<<"!";
				break;
		}
		cout<<arg_1<<"\n";
	}
	else if(op >= IF_LESS && op <= IF_NOT_EXPRESSION)
	{
		cout<<"if "<<arg_1<<" ";
		switch(op)
		{
			case IF_LESS:
				cout<<"<";
				break;

			case IF_GREATER:
				cout<<">";
				break;
			case IF_LESS_EQUAL:
				cout<<"<=";
				break;
			case IF_GREATER_EQUAL:
				cout<<">=";
				break;
			case IF_IS_EQUAL:
				cout<<"==";
				break;
			case IF_NOT_EQUAL:
				cout<<"!=";
				break;
			case IF_EXPRESSION:
				cout<<"!= 0";
				break;
			case IF_NOT_EXPRESSION:
				cout<<"== 0";
				break;
		}
		//printf("%s goto %s\n", arg_2, result);
		cout<<arg_2<<" goto "<<result<<"\n";
	}
	else if(op == GOTO)
	{
		//printf("goto %s\n", result);
		cout<<"goto "<<result<<"\n";
	}
	else if (op == COPY)
	{
		//printf("%s = %s\n", result, arg_1);
		cout<<result<<" = "<<arg_1<<"\n";
	}
	else if (op == ARRAY_ACCESS)
	{
		//printf("%s = %s[%s]\n", result, arg_1, arg_2);
		cout<<result<<" = "<<arg_1<<"["<<arg_2<<"]\n";
	}
	else if (op == ARRAY_DEREFERENCE)
	{
		//printf("%s[%s] = %s", result, arg_2, arg_1);
		cout<<result<<"["<<arg_2<<"] = "<<arg_1;
	}
	else if(op == CALL)
	{
		//printf("call %s %s\n", result, arg_1);
		cout<<"call "<<result<<" "<<arg_1<<"\n";
	}
	else if (op == PARAM)
	{
		//printf("param %s\n", result);
		cout<<"param "<<result<<"\n";
	}
	else if (op == RETURN)
	{
		//printf("return %s\n", result);
		cout<<"return "<<result<<"\n";
	}
	else if (op == RETURN_VOID)
	{
		//printf("return\n");
		cout<<"return\n";
	}
	else if (op >= C2I && op <= D2I)
	{
		cout<<result<<" = ";
		switch(op)
		{
			case C2I :
				cout<<" Char2Int(" <<arg_1<<")" <<endl;
				break;
            case C2D :
            	cout<<" Char2Double(" <<arg_1<<")" <<endl;
            	break;
            case I2C :
            	cout<<" Int2Char("<<arg_1<<")"<<endl;
            	break;
            case D2C :
            	cout<<" Double2Char("<<arg_1<<")"<<endl;
            	break;
            case I2D :
            	cout<<" Int2Double("<<arg_1<<")"<<endl;
            	break;
            case D2I :
            	cout<<" Double2Int("<<arg_1<<")"<<endl;
            	break;
		}
	}
	else if (op == _FUNCTION_START)
	{
		cout<<"function "<<result<<" start\n";
	}
	else if (op == _FUNCTION_END)
	{
		cout<<"function "<<result<<" end\n";
	}


	//need to add more code here
}

void Quad_Array :: emit(opcodeType op, string result, string arg_1, string arg_2)
{
	Quad q;
	//copy the opcodes, result, argument1 and argument 2 to the quad q
	q.op = op;
	q.result = result;
	q.arg_1 = arg_1;	//check these
	q.arg_2 = arg_2;
	//pushback the quad q to the array of quads
	arr.push_back(q);
	//after emit gets completed, increment global quad_array index pointer
	index++;
}

void Quad_Array :: emit(opcodeType op, string result, int num)
{
	Quad q;
	q.op = op;
	q.result = result;
	string s = to_string(num);
	q.arg_1 = s;
	arr.push_back(q);
	index++;
}

void Quad_Array :: emit(opcodeType op, string result, double double_num)
{
	Quad q;
	q.op = op;
	q.result = result;
	string s = to_string(double_num);
	q.arg_1 = s;
	arr.push_back(q);
	index++;
}

void Quad_Array :: emit(opcodeType op, string result, char char_const)
{
	Quad q;
	q.op = op;
	q.result = result;
	string s = "";
	s = s + char_const;
	q.arg_1 = s;
	arr.push_back(q);
	index++;
}

void Quad_Array :: backpatch(list<int> bp_list, int i)
{
	string s = to_string(i);
	list<int>::iterator it;
	for(it = bp_list.begin(); it != bp_list.end(); it++)
	{
		arr[*it].result = s;
	}
}

//type conversions
void Quad_Array :: convD2I(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name.compare("int")==0)
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "int";
		emit(D2I, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convD2C(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name.compare("char")==0)
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "char";
		emit(D2C, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convI2D(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name.compare("double")==0)
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "double";
		emit(I2D, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convI2C(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name.compare("char")==0)
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "char";
		emit(I2C, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convC2D(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name.compare("double")==0)
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "double";
		emit(C2D, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convC2I(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name.compare("int")==0)
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "int";
		emit(C2I, e1->loc, e2->loc, "");
	}
}


void Quad_Array :: convInt2Bool(exp_attr *exp)
{
	type_inf bool_type;
	bool_type.type_name = "bool";
	if(exp->type.type_name.compare("bool")==0)
		return;
	if(exp->type.type_name.compare("int")==0)
	{
		backpatch(exp->truelist, index);
		backpatch(exp->falselist,index);
		exp->falselist = makelist(index);
		emit(IF_NOT_EXPRESSION,"",exp->loc,"");
		//emit(COPY, exp->loc, "~1","");
		exp->truelist = makelist(index);
		emit(GOTO,"","","");
	}
	exp->type.type_name = "bool";

}


symtab* symboltable :: lookup(string s, string type, int pc)
{
	symtab *sp;
	for(sp = sym_table; sp < &sym_table[MAX]; sp++)
	{
		//cout<<s<<"\n";
		if(!sp->id.empty() && !sp->id.compare(s))
		{
			return sp;
		}
		if(sp->id.empty())
		{
			sp = new symtab;
			sp->id = s;
			//include type
			type_inf t;

			t.type_name = type;
			int t_size = 0;
			if(pc == 0)
			{
			if(type.compare("int") == 0)
				t_size = 4;
			else if(type.compare("double") == 0)
				t_size = 8;
			else if(type.compare("char") == 0)
				t_size = 1;
			else if(type.compare("function")==0 || type.compare("void")==0)
				t_size = 0;
			t.size = t_size;
			//cout<<t.type_name;
			sp->type = t;
			sp->size = t_size;
			sp->nested_table = NULL;
			//cout<<t_size<<"\n";
			//cout<<sp->type.type_name<<"\n";
			sp->offset = offset;
			offset = offset + t_size;

			sym_table[no_of_entries] = *sp;
			no_of_entries++;
			//cout<<sp->id<<"\n";
			//cout<<no_of_entries<<"\n";
			break;
			}
			else
			{
				sp->size = 4;
				sp->type.type_name = type;
				sp->array_type.type_name = "array";
				sp->pc = pc;
			}

		}
	}
	/*for(i=0;i<no_of_entries;i++)
	{
		sp = &sym_table[i];
		if(!sp->id.empty() && !sp->id.compare(s))
		{
			return sp;
		}
		if(sp->id.empty())
		{
			sp->id = s;
			//include type
			type_inf t;

			t.type_name = type;
			int t_size = 0;
			if(pc == 0)
			{
			if(type.compare("int") == 0)
				t_size = 4;
			else if(type.compare("double") == 0)
				t_size = 8;
			else if(type.compare("char") == 0)
				t_size = 1;
			else if(type.compare("function") || type.compare("void"))
				t_size = 0;
			t.size = t_size;
			cout<<t.type_name;
			sp->type = t;
			sp->size = t_size;
			//cout<<t_size<<"\n";
			sp->offset = sp->offset + t_size;
			no_of_entries++;
			break;
			}
			else
			{
				sp->size = 4;
				sp->type.type_name = type;
				sp->array_type.type_name = "array";
				sp->pc = pc;
			}

		}
	}*/
	return sp;
}

string symboltable :: gentemp(type_inf type)
{
	//maintain counts generated
	static int temporary_count = 0;
	string s = "t";
	s = s + to_string(temporary_count);
	temporary_count++;
	//id
	//lookup(s, type.type_name);
	sym_table[no_of_entries].id = s;
	//type
	sym_table[no_of_entries].type = type;
	//size
	int t_size = 0;
	if(type.type_name.compare("int") == 0)
		t_size = 4;
	else if(type.type_name.compare("double") == 0)
		t_size = 8;
	else if(type.type_name.compare("char") == 0)
		t_size = 1;
	else if(type.type_name.compare("function")==0 || type.type_name.compare("void")==0)
		t_size = 0;
	sym_table[no_of_entries].size = t_size;
	//initial value
	sym_table[no_of_entries].init_val = NULL;
	//offset
	sym_table[no_of_entries].offset = offset;
	sym_table[no_of_entries].nested_table = NULL;
	offset = offset + t_size;


	no_of_entries++;
	return s;
}

void symboltable:: print()
{
	int i;
	cout<<"Name\tType\t\tSize\tOffset\n";
	cout<<"---------------------------------------\n";
	for(i=0;i<no_of_entries;i++)
	{
		cout<<sym_table[i].id<<"\t";
		if(sym_table[i].type.type_name.compare("int")==0)
			cout<<"int\t";
		else if(sym_table[i].type.type_name.compare("char")==0)
			cout<<"char\t";
		else if(sym_table[i].type.type_name.compare("double")==0)
			cout<<"double\t";
		else if(sym_table[i].type.type_name.compare("function")==0)
			cout<<"function\t";
		cout<<"\t"<<sym_table[i].size<<"\t";
		cout<<sym_table[i].offset<<"\t";
		//cout<<sym_table[i].
		cout<<"\n";
	}
}
list<int> makelist(int index)
{
    list<int> temp;
    temp.push_back(index);
    return temp;
}

list<int> merge(list<int> a, list<int> b)
{
    list<int> temp;
    temp.merge(a);
    temp.merge(b);
    return temp;
}

/*int main()
{
    yydebug = 1;
    bool failure = yyparse();
    int size = Q_arr.arr.size();
    for(int i = 0; i<size;i++)
    {
        cout<<i<<": "; Q_arr.arr[i].print();
    }
    cout<<"----------------SYMBOL TABLE----------------"<<endl;
    symboltable *g = &GT;
    g->print();
    cout<<"--------------------------------------------"<<endl;
    cout<<g->no_of_entries<<endl;
    for(int i=0; i<g->no_of_entries;i++)
    {
        symtab t = (g->sym_table[i]);
        if(t.nested_table != NULL)
        {
            cout<<"----------------SYMBOL TABLE("<<t.id<<")----------------"<<endl;
            t.nested_table->print();
            cout<<"--------------------------------------------"<<endl;
        }
    }
    if(failure)
        printf("failure\n");
    else
        printf("success\n");

}*/
