#include <obs-module.h>
#include <obs-frontend-api.h>
#include <obs.hpp>
#include <util/util.hpp>
#include <QAction>
#include "simple-edit.h"

using namespace std;

SimpleEditor *se;

SimpleEditor::SimpleEditor()
{
}

void SimpleEditor::callJavaApp() {
	if (system(NULL)) {
		blog(LOG_INFO, "Shell available.");
		// Need to find better way to do this...
		system("start javaw -jar D:\\Repos\\AV-Cart\\target\\AVCart-1.0-SNAPSHOT.jar");
	}
	else {
		blog(LOG_INFO, "Shell unavailable. Cannot launch Simple Editor");
	}
	
}

extern "C" void FreeSimpleEditor()
{
}

extern "C" void InitSimpleEditor()
{
	QAction *action = (QAction*)obs_frontend_add_tools_menu_qaction("Simple-Edit");

	//obs_frontend_push_ui_translation(obs_module_get_string);

	se = new SimpleEditor();

	auto cb = []()
	{
		//Function that is called upon 'Tools' menu item click.
		se->callJavaApp();
	};

	//obs_frontend_pop_ui_translation();

	//obs_frontend_add_save_callback(SaveOutputTimer, nullptr);
	//obs_frontend_add_event_callback(OBSEvent, nullptr);

	action->connect(action, &QAction::triggered, cb);
}
