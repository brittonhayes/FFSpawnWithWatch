# FF - Spawn with a Watch

Automatically equips players with a watch when they spawn in Arma Reforger.

## How-to

### Install
[Subscribe on Workshop](https://reforger.armaplatform.com/workshop/685767F866F5A6F8-FF-Spawnwithawatch) or place in your `addons` folder and enable in Workbench.

### Change watch model
Edit `m_WatchPrefab` in `Scripts/Game/GameMode/FFSW_GiveWatchOnSpawn.c`:
```c
protected ResourceName m_WatchPrefab = "{PREFAB_ID}Prefabs/Items/Equipment/Watches/YourWatch.et";
```

## Reference

**Dependencies**: JWK Respawn System

**Main script**: `Scripts/Game/GameMode/FFSW_GiveWatchOnSpawn.c`

**Default watch**: Sand Y184A (`{78ED4FEF62BBA728}Prefabs/Items/Equipment/Watches/Watch_SandY184A.et`)

**Behavior**: Checks inventory to prevent duplicates on spawn/respawn

## Background

Extends JWK Respawn System to provide watches on spawn.

Developed using [Freedom Fighters Modding Guidelines](https://www.johnnykerner.dev/FreedomFighters/modding/guidelines/index.html).

---

Public domain. See [LICENSE](LICENSE).
