#include <Evaluator.hpp>

AST* builtin_function_print(std::vector<AST*> args)
{
    if (args.size() == 0)
    {
        printf("Error: print expected at least one argument.\n");
        exit(1);
    }

    for (auto it = args.begin(); it != args.end(); it++)
    {
        AST* argument = (*it);
        if (argument->value_str == 0) continue;

        printf("%s\n", argument->value_str);
    }

    return new AST(ASTType::AST_NULL); 
}

Evaluator::Evaluator()
{
    this->builtin_functions["print"] = builtin_function_print;
}

AST* Evaluator::evaluate_compound(AST* ast)
{
    for (auto it = ast->children.begin(); it != ast->children.end(); it++)
    {
        AST* child = (*it);
        this->evaluate(child);
    }
}

AST* Evaluator::evaluate_var_def(AST* ast)
{
    std::string name(ast->name);
    AST* value = this->evaluate(ast->right);

    this->memory[name] = value;

    return value;
}

AST* Evaluator::evaluate_string(AST* ast)
{
    return ast;
}

AST* Evaluator::evaluate_number(AST* ast)
{
    return ast;
}

AST* Evaluator::evaluate_id(AST* ast)
{
    if (this->memory.find(ast->name) == this->memory.end())
    {
        printf("Undefined variable %s\n", ast->name);
        exit(1);
    }

    AST* value = this->memory[ast->name];

    return value;
}

AST* Evaluator::evaluate_function_call(AST* ast)
{
    char* name = ast->name;
    if (this->builtin_functions.find(name) == this->builtin_functions.end())
    {
        printf("Undefined function %s\n", name);
        exit(1);
    }

    for (auto it = ast->args.begin(); it != ast->args.end(); it++)
    {
        AST* argument = (*it);
        argument = this->evaluate(argument);
    }

    BuiltinFunction func = this->builtin_functions[name];

    return func(ast->args);
}

AST* Evaluator::evaluate(AST* ast)
{
    switch (ast->type)
    {
        case ASTType::AST_COMPOUND: return this->evaluate_compound(ast); break;
        case ASTType::AST_INT: return this->evaluate_number(ast); break;
        case ASTType::AST_STRING: return this->evaluate_string(ast); break;
        case ASTType::AST_ID: return this->evaluate_id(ast); break;
        case ASTType::AST_VAR_DEF: return this->evaluate_var_def(ast); break;
        case ASTType::AST_FUNCTION_CALL: return this->evaluate_function_call(ast); break;
        default: { return ast; }
    }

    return ast;
}
