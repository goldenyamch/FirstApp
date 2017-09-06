#ifndef FIRST_APPTESTAPP_H
#define FIRST_APPTESTAPP_H

#include "MooseApp.h"

class FirstAppTestApp;

template <>
InputParameters validParams<FirstAppTestApp>();

class FirstAppTestApp : public MooseApp
{
public:
  FirstAppTestApp(InputParameters parameters);
  virtual ~FirstAppTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* FIRST_APPTESTAPP_H */
