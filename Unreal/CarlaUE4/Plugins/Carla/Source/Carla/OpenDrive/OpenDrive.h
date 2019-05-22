// Copyright (c) 2019 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "Carla/OpenDrive/OpenDriveMap.h"

#include "Kismet/BlueprintFunctionLibrary.h"

#include "OpenDrive.generated.h"

UCLASS()
class CARLA_API UOpenDrive : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()

public:

  static FString FindPathToXODRFile(const FString &MapName);

  /// Return the OpenDrive XML associated to @a MapName, or empty if the file
  /// is not found.
  UFUNCTION(BlueprintCallable, Category="CARLA|OpenDrive")
  static FString LoadXODR(const FString &MapName);

  UFUNCTION(BlueprintCallable, Category="CARLA|OpenDrive")
  static UOpenDriveMap *LoadOpenDriveMap(const FString &MapName);

  UFUNCTION(BlueprintPure, Category="CARLA|OpenDrive", meta=(WorldContext="WorldContextObject"))
  static UOpenDriveMap *LoadCurrentOpenDriveMap(const UObject *WorldContextObject);
};
