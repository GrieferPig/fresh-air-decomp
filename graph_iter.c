
void graph_iter(longlong param_1, undefined8 *param_2)

{
    longlong *plVar1;
    int *piVar2;
    longlong *plVar3;
    int iVar4;
    longlong lVar5;
    int iVar6;
    int iVar7;
    ulonglong uVar8;
    uint local_res18[2];
    longlong local_b8;
    longlong *local_b0;
    longlong local_a8;
    longlong *local_a0;
    longlong local_98;
    longlong *local_90;
    longlong local_88;
    longlong *local_80;
    longlong local_78;
    longlong *local_70;
    longlong local_68;
    longlong *local_60;
    longlong local_58;
    longlong *local_50;
    longlong local_48;
    longlong *local_40;

    lVar5 = FUN_180c8b9c0(*(longlong *)(param_1 + 0x90) + 0xa080);
    iVar7 = 0;
    if (0 < (int)lVar5)
    {
        local_res18[0] = 1;
        local_res18[1] = 0;
        FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa080, &local_b8, 0);
        uVar8 = FUN_18103fd60();
        FUN_180c9d700(local_b8, 0x157, (int)uVar8, local_res18);
        if (local_b0 != (longlong *)0x0)
        {
            LOCK();
            plVar1 = local_b0 + 1;
            lVar5 = *plVar1;
            *(int *)plVar1 = (int)*plVar1 + -1;
            UNLOCK();
            if ((int)lVar5 == 1)
            {
                (**(code **)(*local_b0 + 8))(local_b0);
                LOCK();
                piVar2 = (int *)((longlong)local_b0 + 0xc);
                iVar6 = *piVar2;
                *piVar2 = *piVar2 + -1;
                UNLOCK();
                if (iVar6 == 1)
                {
                    (**(code **)(*local_b0 + 0x10))(local_b0);
                }
            }
        }
        FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa080, &local_a8, 0);
        uVar8 = FUN_18103fd60();
        FUN_180c9d700(local_a8, 0x158, (int)uVar8, local_res18);
        if (local_a0 != (longlong *)0x0)
        {
            LOCK();
            plVar1 = local_a0 + 1;
            lVar5 = *plVar1;
            *(int *)plVar1 = (int)*plVar1 + -1;
            UNLOCK();
            if ((int)lVar5 == 1)
            {
                (**(code **)(*local_a0 + 8))(local_a0);
                LOCK();
                piVar2 = (int *)((longlong)local_a0 + 0xc);
                iVar6 = *piVar2;
                *piVar2 = *piVar2 + -1;
                UNLOCK();
                if (iVar6 == 1)
                {
                    (**(code **)(*local_a0 + 0x10))(local_a0);
                }
            }
        }
        FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa080, &local_98, 0);
        FUN_180c9d700(local_98, 0x15a, *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x9e60), local_res18);
        if (local_90 != (longlong *)0x0)
        {
            LOCK();
            plVar1 = local_90 + 1;
            lVar5 = *plVar1;
            *(int *)plVar1 = (int)*plVar1 + -1;
            UNLOCK();
            if ((int)lVar5 == 1)
            {
                (**(code **)(*local_90 + 8))(local_90);
                LOCK();
                piVar2 = (int *)((longlong)local_90 + 0xc);
                iVar6 = *piVar2;
                *piVar2 = *piVar2 + -1;
                UNLOCK();
                if (iVar6 == 1)
                {
                    (**(code **)(*local_90 + 0x10))(local_90);
                }
            }
        }
    }
    lVar5 = FUN_180c8b9c0(*(longlong *)(param_1 + 0x90) + 0xa080);
    iVar6 = iVar7;
    if (0 < (int)lVar5)
    {
        do
        {
            FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa080, &local_88, iVar6);
            FUN_180ca0d50(local_88, (longlong)param_2);
            plVar1 = local_80;
            if (local_80 != (longlong *)0x0)
            {
                LOCK();
                plVar3 = local_80 + 1;
                lVar5 = *plVar3;
                *(int *)plVar3 = (int)*plVar3 + -1;
                UNLOCK();
                if ((int)lVar5 == 1)
                {
                    (**(code **)(*local_80 + 8))(local_80);
                    LOCK();
                    piVar2 = (int *)((longlong)plVar1 + 0xc);
                    iVar4 = *piVar2;
                    *piVar2 = *piVar2 + -1;
                    UNLOCK();
                    if (iVar4 == 1)
                    {
                        (**(code **)(*plVar1 + 0x10))(plVar1);
                    }
                }
            }
            iVar6 = iVar6 + 1;
            lVar5 = FUN_180c8b9c0(*(longlong *)(param_1 + 0x90) + 0xa080);
        } while (iVar6 < (int)lVar5);
    }
    lVar5 = FUN_180c8b9c0(*(longlong *)(param_1 + 0x90) + 0xa080);
    iVar6 = 0;
    if (0 < (int)lVar5)
    {
        do
        {
            FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa080, &local_78, iVar7);
            FUN_180ca2450(local_78, (ulonglong) * (uint *)(param_2 + 5));
            plVar1 = local_70;
            if (local_70 != (longlong *)0x0)
            {
                LOCK();
                plVar3 = local_70 + 1;
                lVar5 = *plVar3;
                *(int *)plVar3 = (int)*plVar3 + -1;
                UNLOCK();
                if ((int)lVar5 == 1)
                {
                    (**(code **)(*local_70 + 8))(local_70);
                    LOCK();
                    piVar2 = (int *)((longlong)plVar1 + 0xc);
                    iVar6 = *piVar2;
                    *piVar2 = *piVar2 + -1;
                    UNLOCK();
                    if (iVar6 == 1)
                    {
                        (**(code **)(*plVar1 + 0x10))(plVar1);
                    }
                }
            }
            FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa080, &local_68, iVar7);
            FUN_180c9f070(local_68, 1.0);
            plVar1 = local_60;
            if (local_60 != (longlong *)0x0)
            {
                LOCK();
                plVar3 = local_60 + 1;
                lVar5 = *plVar3;
                *(int *)plVar3 = (int)*plVar3 + -1;
                UNLOCK();
                if ((int)lVar5 == 1)
                {
                    (**(code **)(*local_60 + 8))(local_60);
                    LOCK();
                    piVar2 = (int *)((longlong)plVar1 + 0xc);
                    iVar6 = *piVar2;
                    *piVar2 = *piVar2 + -1;
                    UNLOCK();
                    if (iVar6 == 1)
                    {
                        (**(code **)(*plVar1 + 0x10))(plVar1);
                    }
                }
            }
            FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa080, &local_58, iVar7);
            FUN_180ca0d90(local_58, param_2, 0, '\x01');
            plVar1 = local_50;
            if (local_50 != (longlong *)0x0)
            {
                LOCK();
                plVar3 = local_50 + 1;
                lVar5 = *plVar3;
                *(int *)plVar3 = (int)*plVar3 + -1;
                UNLOCK();
                if ((int)lVar5 == 1)
                {
                    (**(code **)(*local_50 + 8))(local_50);
                    LOCK();
                    piVar2 = (int *)((longlong)plVar1 + 0xc);
                    iVar6 = *piVar2;
                    *piVar2 = *piVar2 + -1;
                    UNLOCK();
                    if (iVar6 == 1)
                    {
                        (**(code **)(*plVar1 + 0x10))(plVar1);
                    }
                }
            }
            FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa080, &local_48, iVar7);
            iVar6 = FUN_180c9e040(local_48);
            plVar1 = local_40;
            if (local_40 != (longlong *)0x0)
            {
                LOCK();
                plVar3 = local_40 + 1;
                lVar5 = *plVar3;
                *(int *)plVar3 = (int)*plVar3 + -1;
                UNLOCK();
                if ((int)lVar5 == 1)
                {
                    (**(code **)(*local_40 + 8))(local_40);
                    LOCK();
                    piVar2 = (int *)((longlong)plVar1 + 0xc);
                    iVar4 = *piVar2;
                    *piVar2 = *piVar2 + -1;
                    UNLOCK();
                    if (iVar4 == 1)
                    {
                        (**(code **)(*plVar1 + 0x10))(plVar1);
                    }
                }
            }
            iVar7 = iVar7 + 1;
            lVar5 = FUN_180c8b9c0(*(longlong *)(param_1 + 0x90) + 0xa080);
        } while (iVar7 < (int)lVar5);
    }
    if (*(int *)(param_1 + 0x58) != iVar6)
    {
        *(int *)(param_1 + 0x58) = iVar6;
        iVar7 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18) * -2;
        if (iVar6 < 0)
        {
            iVar6 = 0;
        }
        if (iVar7 < iVar6)
        {
            iVar6 = iVar7;
        }
        if ((*(int *)(param_1 + 0x20) != iVar6) && (*(int *)(param_1 + 0x20) = iVar6, 0 < iVar6))
        {
            *(undefined8 *)(param_1 + 0x24) = 0;
        }
        iVar6 = *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x38) * -2;
        iVar7 = *(int *)(param_1 + 0x58);
        if (iVar7 < 0)
        {
            iVar7 = 0;
        }
        if (iVar6 < iVar7)
        {
            iVar7 = iVar6;
        }
        if ((*(int *)(param_1 + 0x40) != iVar7) && (*(int *)(param_1 + 0x40) = iVar7, 0 < iVar7))
        {
            *(undefined8 *)(param_1 + 0x44) = 0;
        }
    }
    return;
}
