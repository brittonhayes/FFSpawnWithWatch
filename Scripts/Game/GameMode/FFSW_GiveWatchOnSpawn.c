// Modded JWK_RespawnSystemComponent to give players configurable items on spawn
// Designed for Freedom Fighters - spawn with essential gear you'd otherwise lack
modded class JWK_RespawnSystemComponent
{
    // ==================== WATCH CONFIGURATION ====================
    [Attribute("1", UIWidgets.CheckBox, "Enable spawning with a watch", category: "Watch")]
    protected bool m_bSpawnWithWatch;

    [Attribute("{78ED4FEF62BBA728}Prefabs/Items/Equipment/Watches/Watch_SandY184A.et", UIWidgets.ResourcePickerThumbnail, "Watch prefab to spawn with", params: "et", category: "Watch")]
    protected ResourceName m_WatchPrefab;

    // ==================== MAP CONFIGURATION ====================
    [Attribute("1", UIWidgets.CheckBox, "Enable spawning with a map", category: "Map")]
    protected bool m_bSpawnWithMap;

    [Attribute("{E98CF259B1E2D5C9}Prefabs/Items/Equipment/Maps/PaperMap_01_folded.et", UIWidgets.ResourcePickerThumbnail, "Map prefab to spawn with", params: "et", category: "Map")]
    protected ResourceName m_MapPrefab;

    // ==================== COMPASS CONFIGURATION ====================
    [Attribute("0", UIWidgets.CheckBox, "Enable spawning with a compass", category: "Compass")]
    protected bool m_bSpawnWithCompass;

    [Attribute("{1D5D5B41D6B2F056}Prefabs/Items/Equipment/Compass/Compass_SY183.et", UIWidgets.ResourcePickerThumbnail, "Compass prefab to spawn with", params: "et", category: "Compass")]
    protected ResourceName m_CompassPrefab;

    // ==================== FLASHLIGHT CONFIGURATION ====================
    [Attribute("0", UIWidgets.CheckBox, "Enable spawning with a flashlight", category: "Flashlight")]
    protected bool m_bSpawnWithFlashlight;

    [Attribute("{7B5B6AE9DA1F3D91}Prefabs/Items/Equipment/Flashlights/Flashlight_01/Flashlight_01_Black.et", UIWidgets.ResourcePickerThumbnail, "Flashlight prefab to spawn with", params: "et", category: "Flashlight")]
    protected ResourceName m_FlashlightPrefab;

    // ==================== RADIO CONFIGURATION ====================
    [Attribute("0", UIWidgets.CheckBox, "Enable spawning with a radio", category: "Radio")]
    protected bool m_bSpawnWithRadio;

    [Attribute("{C8D9EEE1AC7D9BDA}Prefabs/Items/Equipment/Radios/Radio_PRC77.et", UIWidgets.ResourcePickerThumbnail, "Radio prefab to spawn with", params: "et", category: "Radio")]
    protected ResourceName m_RadioPrefab;

    override protected void SetupPlayerInventory(int playerId, bool isFirstSpawn, IEntity character, JWK_RespawnLoadoutHandler handler)
    {
        super.SetupPlayerInventory(playerId, isFirstSpawn, character, handler);

        if (!character)
            return;

        SCR_InventoryStorageManagerComponent inventoryManager = SCR_InventoryStorageManagerComponent.Cast(
            character.FindComponent(SCR_InventoryStorageManagerComponent));

        if (!inventoryManager)
            return;

        // Give configured items
        if (m_bSpawnWithWatch)
            GiveItemIfMissing(inventoryManager, character, m_WatchPrefab, "watch");

        if (m_bSpawnWithMap)
            GiveItemIfMissing(inventoryManager, character, m_MapPrefab, "map");

        if (m_bSpawnWithCompass)
            GiveItemIfMissing(inventoryManager, character, m_CompassPrefab, "compass");

        if (m_bSpawnWithFlashlight)
            GiveItemIfMissing(inventoryManager, character, m_FlashlightPrefab, "flashlight");

        if (m_bSpawnWithRadio)
            GiveItemIfMissing(inventoryManager, character, m_RadioPrefab, "radio");
    }

    protected void GiveItemIfMissing(SCR_InventoryStorageManagerComponent inventoryManager, IEntity playerEntity, ResourceName prefab, string itemType)
    {
        if (!prefab || prefab == string.Empty)
        {
            Print(string.Format("[FFSpawnKit] No prefab configured for %1", itemType), LogLevel.WARNING);
            return;
        }

        if (HasItemOfType(inventoryManager, itemType))
        {
            Print(string.Format("[FFSpawnKit] Player already has %1, skipping", itemType), LogLevel.DEBUG);
            return;
        }

        Resource itemResource = Resource.Load(prefab);
        if (!itemResource || !itemResource.IsValid())
        {
            Print(string.Format("[FFSpawnKit] Failed to load %1 prefab: %2", itemType, prefab), LogLevel.ERROR);
            return;
        }

        EntitySpawnParams spawnParams = new EntitySpawnParams();
        spawnParams.TransformMode = ETransformMode.WORLD;
        playerEntity.GetWorldTransform(spawnParams.Transform);

        IEntity itemEntity = GetGame().SpawnEntityPrefab(itemResource, GetGame().GetWorld(), spawnParams);
        if (!itemEntity)
        {
            Print(string.Format("[FFSpawnKit] Failed to spawn %1 entity", itemType), LogLevel.ERROR);
            return;
        }

        if (inventoryManager.InsertItem(itemEntity, null, null, null))
        {
            Print(string.Format("[FFSpawnKit] Gave player %1", itemType), LogLevel.DEBUG);
        }
        else
        {
            Print(string.Format("[FFSpawnKit] Failed to insert %1 into inventory (inventory may be full)", itemType), LogLevel.WARNING);
            SCR_EntityHelper.DeleteEntityAndChildren(itemEntity);
        }
    }

    protected bool HasItemOfType(SCR_InventoryStorageManagerComponent inventoryManager, string itemType)
    {
        array<IEntity> items = {};
        inventoryManager.GetItems(items);

        string searchTerm = itemType;
        searchTerm.ToLower();

        foreach (IEntity item : items)
        {
            if (!item)
                continue;

            EntityPrefabData prefabData = item.GetPrefabData();
            if (!prefabData)
                continue;

            string itemPath = prefabData.GetPrefabName();
            itemPath.ToLower();

            if (itemPath.IndexOf(searchTerm) > -1)
                return true;
        }

        return false;
    }
}
