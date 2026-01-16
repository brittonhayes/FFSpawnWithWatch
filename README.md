# FF - Spawn with a Watch

A simple Arma Reforger mod that automatically equips players with a watch when they spawn.

## Description

This mod extends the JWK Respawn System to automatically give every player a Sand Y184A watch upon spawning. The mod checks if the player already has a watch to avoid duplicates.

## Features

- Automatically equips players with a watch on spawn
- Works with first spawn and respawns
- Prevents duplicate watches by checking inventory
- Compatible with JWK Respawn System

## Requirements

- Arma Reforger
- JWK Respawn System (dependency)

## Installation

### Workshop (Recommended)
Subscribe to the mod on the Arma Reforger Workshop (link TBD)

### Manual Installation
1. Download the mod
2. Place in your Arma Reforger `addons` folder
3. Enable in Arma Reforger Workbench or server configuration

## Configuration

The watch prefab can be modified in the code:
```c
protected ResourceName m_WatchPrefab = "{78ED4FEF62BBA728}Prefabs/Items/Equipment/Watches/Watch_SandY184A.et";
```

Change this path to use a different watch model if desired.

## Development

### File Structure
```
FFSpawnWithWatch/
├── Scripts/
│   └── Game/
│       └── GameMode/
│           └── FFSW_GiveWatchOnSpawn.c
├── addon.gproj
├── LICENSE
└── README.md
```

### Building
Open the project in Arma Reforger Workbench and build using the standard mod building process.

## License

This is free and unencumbered software released into the public domain. See [LICENSE](LICENSE) for details.

## Credits

This mod was developed using the [Freedom Fighters Modding Guidelines](https://www.johnnykerner.dev/FreedomFighters/modding/guidelines/index.html) by Johnny Kerner. Special thanks to the Freedom Fighters community for their modding resources and documentation.

Built using the Enfusion Workbench for Arma Reforger.
