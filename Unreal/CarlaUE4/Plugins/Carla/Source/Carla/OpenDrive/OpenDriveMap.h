// Copyright (c) 2019 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include <compiler/disable-ue4-macros.h>
#include <carla/road/Map.h>
#include <compiler/enable-ue4-macros.h>

#include "OpenDriveMap.generated.h"

USTRUCT(BlueprintType)
struct CARLA_API FWaypoint
{
  GENERATED_BODY()

  carla::road::element::Waypoint Waypoint;
};

USTRUCT(BlueprintType)
struct CARLA_API FWaypointConnection
{
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite)
  FWaypoint Start;

  UPROPERTY(BlueprintReadWrite)
  FWaypoint End;
};

UCLASS(BlueprintType, Blueprintable)
class CARLA_API UOpenDriveMap : public UObject
{
  GENERATED_BODY()

  // ===========================================================================
  // -- Constructor ------------------------------------------------------------
  // ===========================================================================

public:

  UOpenDriveMap(const FObjectInitializer &ObjectInitializer);

  // ===========================================================================
  // -- ------------------------------------------------------------------------
  // ===========================================================================

public:

  UFUNCTION(BlueprintCallable)
  bool HasMap() const
  {
    return Map.IsSet();
  }

  UFUNCTION(BlueprintCallable)
  bool Load(const FString &XODRContent);

  // ===========================================================================
  // -- ------------------------------------------------------------------------
  // ===========================================================================

public:

  UFUNCTION(BlueprintCallable)
  FWaypoint GetClosestWaypointOnRoad(FVector Location, bool &Success) const;

  UFUNCTION(BlueprintCallable)
  TArray<FWaypoint> GenerateWaypoints(float ApproxDistance) const;

  UFUNCTION(BlueprintCallable)
  TArray<FWaypointConnection> GenerateTopology() const;

  UFUNCTION(BlueprintCallable)
  TArray<FWaypoint> GenerateWaypointsOnRoadEntries() const;

  UFUNCTION(BlueprintCallable)
  FVector ComputeLocation(FWaypoint Waypoint) const;

  UFUNCTION(BlueprintCallable)
  TArray<FVector> ComputeLocations(const TArray<FWaypoint> &Waypoints) const;

  UFUNCTION(BlueprintCallable)
  FTransform ComputeTransform(FWaypoint Waypoint) const;

  UFUNCTION(BlueprintCallable)
  TArray<FTransform> ComputeTransforms(const TArray<FWaypoint> &Waypoints) const;

  UFUNCTION(BlueprintCallable)
  TArray<FWaypoint> GetNext(FWaypoint Waypoint, float Distance) const;

private:

  TOptional<carla::road::Map> Map;
};
