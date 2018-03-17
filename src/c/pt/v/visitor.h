#ifndef AFRONT_C_PT_V_VISITOR_H
#define AFRONT_C_PT_V_VISITOR_H

#include "../pt_classes.h"

class visitor {
public:
  visitor(){};
  virtual ~visitor(){};

  virtual void descend() {}
  virtual void ascend() {}

  virtual void v(abstract_array_declarator *a) = 0;
  virtual void v(abstract_declarator *a) = 0;
  virtual void v(abstract_function_declarator *a) = 0;
  virtual void v(additive_expr *a) = 0;
  virtual void v(alignment_specifier *a) = 0;
  virtual void v(and_expr *a) = 0;
  virtual void v(argument_expr_list *a) = 0;
  virtual void v(array_declarator *a) = 0;
  virtual void v(assignment_expr *a) = 0;
  virtual void v(assignment_operator *a) = 0;
  virtual void v(atomic_type_specifier *a) = 0;
  virtual void v(block_item *a) = 0;
  virtual void v(block_item_list *a) = 0;
  virtual void v(cast_expr *a) = 0;
  virtual void v(character_constant *a) = 0;
  virtual void v(compound_statement *a) = 0;
  virtual void v(conditional_expr *a) = 0;
  virtual void v(constant *a) = 0;
  virtual void v(constant_expr *a) = 0;
  virtual void v(declaration *a) = 0;
  virtual void v(declaration_list *a) = 0;
  virtual void v(declaration_specifiers *a) = 0;
  virtual void v(declarator *a) = 0;
  virtual void v(direct_abstract_declarator *a) = 0;
  virtual void v(direct_declarator *a) = 0;
  virtual void v(enumeration_constant *a) = 0;
  virtual void v(enumerator *a) = 0;
  virtual void v(enumerator_list *a) = 0;
  virtual void v(enum_specifier *a) = 0;
  virtual void v(equality_expr *a) = 0;
  virtual void v(exclusive_or_expr *a) = 0;
  virtual void v(expr *a) = 0;
  virtual void v(expression_statement *a) = 0;
  virtual void v(external_definition *a) = 0;
  virtual void v(floating_constant *a) = 0;
  virtual void v(function_body *a) = 0;
  virtual void v(function_declarator *a) = 0;
  virtual void v(function_definition *a) = 0;
  virtual void v(function_specifier *a) = 0;
  virtual void v(generic_association *a) = 0;
  virtual void v(generic_assoc_list *a) = 0;
  virtual void v(generic_selection *a) = 0;
  virtual void v(identifier *a) = 0;
  virtual void v(identifier_list *a) = 0;
  virtual void v(inclusive_or_expr *a) = 0;
  virtual void v(init_declarator *a) = 0;
  virtual void v(init_declarator_list *a) = 0;
  virtual void v(initializer *a) = 0;
  virtual void v(initializer_list *a) = 0;
  virtual void v(integer_constant *a) = 0;
  virtual void v(iteration_statement *a) = 0;
  virtual void v(jump_statement *a) = 0;
  virtual void v(labeled_statement *a) = 0;
  virtual void v(logical_and_expr *a) = 0;
  virtual void v(logical_or_expr *a) = 0;
  virtual void v(multiplicative_expr *a) = 0;
  virtual void v(m *a) = 0;
  virtual void v(n *a) = 0;
  virtual void v(parameter_declaration *a) = 0;
  virtual void v(parameter_list *a) = 0;
  virtual void v(parameter_type_list *a) = 0;
  virtual void v(pointer *a) = 0;
  virtual void v(postfix_expr *a) = 0;
  virtual void v(primary_expr *a) = 0;
  virtual void v(relation_expr *a) = 0;
  virtual void v(selection_statement *a) = 0;
  virtual void v(shift_expr *a) = 0;
  virtual void v(specifier_qualifier_list *a) = 0;
  virtual void v(statement *a) = 0;
  virtual void v(statement_list *a) = 0;
  virtual void v(static_assert_declaration *a) = 0;
  virtual void v(storage_class_specifier *a) = 0;
  virtual void v(struct_declaration *a) = 0;
  virtual void v(struct_declaration_list *a) = 0;
  virtual void v(struct_declarator *a) = 0;
  virtual void v(struct_declarator_list *a) = 0;
  virtual void v(struct_or_union *a) = 0;
  virtual void v(struct_or_union_specifier *a) = 0;
  virtual void v(translation_unit *a) = 0;
  virtual void v(type_name *a) = 0;
  virtual void v(type_qualifier *a) = 0;
  virtual void v(type_qualifier_list *a) = 0;
  virtual void v(type_specifier *a) = 0;
  virtual void v(typedef_name *a) = 0;
  virtual void v(unary_expr *a) = 0;
  virtual void v(unary_operator *a) = 0;
};

#endif
