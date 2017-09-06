#include "FirstAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<FirstAppApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

FirstAppApp::FirstAppApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  FirstAppApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  FirstAppApp::associateSyntax(_syntax, _action_factory);
}

FirstAppApp::~FirstAppApp() {}

// External entry point for dynamic application loading
extern "C" void
FirstAppApp__registerApps()
{
  FirstAppApp::registerApps();
}
void
FirstAppApp::registerApps()
{
  registerApp(FirstAppApp);
}

void
FirstAppApp::registerObjectDepends(Factory & /*factory*/)
{
}

// External entry point for dynamic object registration
extern "C" void
FirstAppApp__registerObjects(Factory & factory)
{
  FirstAppApp::registerObjects(factory);
}
void
FirstAppApp::registerObjects(Factory & /*factory*/)
{
}

void
FirstAppApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
FirstAppApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  FirstAppApp::associateSyntax(syntax, action_factory);
}
void
FirstAppApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
