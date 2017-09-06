#ifndef FIRST_APPAPP_H
#define FIRST_APPAPP_H

#include "MooseApp.h"

class FirstAppApp;

template <>
InputParameters validParams<FirstAppApp>();

class FirstAppApp : public MooseApp
{
public:
  FirstAppApp(InputParameters parameters);
  virtual ~FirstAppApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* FIRST_APPAPP_H */
