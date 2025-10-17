// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/*
 * Interface for the Lego Ability Editor.
 */
class ILegoAbilityEditorModule : public IModuleInterface
{
public:
	/**
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline ILegoAbilityEditorModule& Get()
	{
		return FModuleManager::LoadModuleChecked<ILegoAbilityEditorModule>("LegoAbilityEditor");
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("LegoAbilityEditor");
	}
};

