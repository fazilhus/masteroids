#pragma once
//------------------------------------------------------------------------------
/**
	Base class for applications, override this class
	and use it as an entry point for your lab.
	
	(C) 2015-2018 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <GL/glew.h>
namespace Core
{
class App
{
public:
	/// constructor
	App();
	/// destructor
	virtual ~App();

	/// open application
	virtual bool Open();
	/// perform per-frame loop
	virtual void Run();
	/// stop application
	virtual void Close();
	/// kill application
	virtual void Exit();

private:
	bool isOpen;
};
} // namespace App