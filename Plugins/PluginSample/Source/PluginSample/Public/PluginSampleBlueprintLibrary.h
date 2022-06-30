#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PluginSampleBlueprintLibrary.generated.h"

UCLASS()
class PLUGINSAMPLE_API UPluginSampleBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()

    /**
    * Check if internet connection is available on a device
    *
    * @return - true if connection is available
    */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = PluginSample)
    static bool CheckInternetConnection();

    /**
    * BlueprintPure specifier is not allowed for functions with no return value 
    * and no output parameters
    */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = PluginSample)
    static bool CallStaticMethod();

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = PluginSample)
    static bool CallInstanceMethod();
};
