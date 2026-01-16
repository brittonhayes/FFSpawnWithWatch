// Modded JWK_RespawnSystemComponent to give players watches on spawn
modded class JWK_RespawnSystemComponent
{
    protected ResourceName m_WatchPrefab = "{78ED4FEF62BBA728}Prefabs/Items/Equipment/Watches/Watch_SandY184A.et";

    override protected void SetupPlayerInventory(int playerId, bool isFirstSpawn, IEntity character, JWK_RespawnLoadoutHandler handler)
    {
        super.SetupPlayerInventory(playerId, isFirstSpawn, character, handler);

        if (character)
            GiveWatch(character);
    }

    protected void GiveWatch(IEntity playerEntity)
    {
        SCR_InventoryStorageManagerComponent inventoryManager = SCR_InventoryStorageManagerComponent.Cast(
            playerEntity.FindComponent(SCR_InventoryStorageManagerComponent));

        if (!inventoryManager)
            return;

        if (HasWatch(inventoryManager))
            return;

        if (!m_WatchPrefab || m_WatchPrefab == string.Empty)
            return;

        Resource watchResource = Resource.Load(m_WatchPrefab);
        if (!watchResource || !watchResource.IsValid())
        {
            Print("[FFSpawnWithWatch] Failed to load watch prefab", LogLevel.ERROR);
            return;
        }

        EntitySpawnParams spawnParams = new EntitySpawnParams();
        spawnParams.TransformMode = ETransformMode.WORLD;
        playerEntity.GetWorldTransform(spawnParams.Transform);

        IEntity watchEntity = GetGame().SpawnEntityPrefab(watchResource, GetGame().GetWorld(), spawnParams);
        if (!watchEntity)
        {
            Print("[FFSpawnWithWatch] Failed to spawn watch entity", LogLevel.ERROR);
            return;
        }

        inventoryManager.InsertItem(watchEntity, null, null, null);
    }

    protected bool HasWatch(SCR_InventoryStorageManagerComponent inventoryManager)
    {
        array<IEntity> items = {};
        inventoryManager.GetItems(items);

        foreach (IEntity item : items)
        {
            if (!item)
                continue;

            string itemPath = item.GetPrefabData().GetPrefabName();
            itemPath.ToLower();

            if (itemPath.IndexOf("watch") > -1)
                return true;
        }

        return false;
    }
}
