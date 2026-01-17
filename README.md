# FF - Spawn Kit

Spawn with essential gear in Freedom Fighters. No more scavenging for a watch before you can rest, or wandering lost without a map.

This mod automatically equips players with configurable items on spawn - watches, maps, compasses, flashlights, and radios. Toggle what you need, pick your preferred models, and get straight to the action.

## Features

| Item | Default | Description |
|------|---------|-------------|
| Watch | **Enabled** | Tell time and rest at beds |
| Map | **Enabled** | Navigate the world |
| Compass | Disabled | Find your bearings |
| Flashlight | Disabled | See in the dark |
| Radio | Disabled | Team communication |

All items check for duplicates - you won't get extras if you already have one.

## How-to

### Install

[Subscribe on Workshop](https://reforger.armaplatform.com/workshop/685767F866F5A6F8-FF-Spawnwithawatch) or place in your `addons` folder and enable in Workbench.

### Configure via Workbench (Recommended)

1. Open your scenario in Workbench
2. Find the `JWK_RespawnSystemComponent` in your GameMode
3. Look for the **Watch**, **Map**, **Compass**, **Flashlight**, and **Radio** categories
4. Toggle items on/off and pick prefabs using the resource picker

### Configure via Code

Edit `Scripts/Game/GameMode/FFSW_GiveWatchOnSpawn.c`:

```c
// Enable/disable items (1 = enabled, 0 = disabled)
[Attribute("1", UIWidgets.CheckBox, "Enable spawning with a watch", category: "Watch")]
protected bool m_bSpawnWithWatch;

[Attribute("1", UIWidgets.CheckBox, "Enable spawning with a map", category: "Map")]
protected bool m_bSpawnWithMap;

// Change prefabs
[Attribute("{78ED4FEF62BBA728}Prefabs/Items/Equipment/Watches/Watch_SandY184A.et", ...)]
protected ResourceName m_WatchPrefab;
```

## Default Prefabs

| Item | Default Prefab |
|------|----------------|
| Watch | `{78ED4FEF62BBA728}Prefabs/Items/Equipment/Watches/Watch_SandY184A.et` |
| Map | `{E98CF259B1E2D5C9}Prefabs/Items/Equipment/Maps/PaperMap_01_folded.et` |
| Compass | `{1D5D5B41D6B2F056}Prefabs/Items/Equipment/Compass/Compass_SY183.et` |
| Flashlight | `{7B5B6AE9DA1F3D91}Prefabs/Items/Equipment/Flashlights/Flashlight_01/Flashlight_01_Black.et` |
| Radio | `{C8D9EEE1AC7D9BDA}Prefabs/Items/Equipment/Radios/Radio_PRC77.et` |

## Reference

**Dependencies**: JWK Respawn System

**Main script**: `Scripts/Game/GameMode/FFSW_GiveWatchOnSpawn.c`

**Behavior**:
- Items given on spawn/respawn
- Duplicate detection prevents stacking
- Failed insertions (full inventory) are cleaned up
- Debug logging with `[FFSpawnKit]` prefix

## Background

Extends JWK Respawn System to provide configurable spawn items.

Developed using [Freedom Fighters Modding Guidelines](https://www.johnnykerner.dev/FreedomFighters/modding/guidelines/index.html).

---

Public domain. See [LICENSE](LICENSE).
