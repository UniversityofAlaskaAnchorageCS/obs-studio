#include <obs-module.h>

OBS_DECLARE_MODULE()
//OBS_MODULE_USE_DEFAULT_LOCALE("simple-edit", "en-US")

void InitSimpleEditor();
void FreeSimpleEditor();

bool obs_module_load(void)
{
	InitSimpleEditor();
	return true;
}

void obs_module_unload(void)
{
	FreeSimpleEditor();
}
