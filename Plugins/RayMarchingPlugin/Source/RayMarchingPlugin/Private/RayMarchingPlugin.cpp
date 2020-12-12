// Copyright Epic Games, Inc. All Rights Reserved.

#include "RayMarchingPlugin.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Interfaces/IPluginManager.h"
#include "ShaderCore.h"

#define LOCTEXT_NAMESPACE "FRayMarchingPluginModule"

void FRayMarchingPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("RayMarchingPlugin"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/PluginShaders"), PluginShaderDir);
}

void FRayMarchingPluginModule::ShutdownModule()
{
	ResetAllShaderSourceDirectoryMappings();
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRayMarchingPluginModule, RayMarchingPlugin)