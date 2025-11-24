
void splitter(longlong param_1, longlong *param_2, undefined8 param_3, undefined8 param_4)

{
    longlong *plVar1;
    int *piVar2;
    int iVar3;
    bool bVar4;
    bool bVar5;
    bool bVar6;
    bool bVar7;
    uint uVar8;
    undefined **ppuVar9;
    longlong lVar10;
    undefined *puVar11;
    longlong *plVar12;
    undefined8 *puVar13;
    char *pcVar14;
    int iVar15;
    longlong lVar16;
    ulonglong uVar17;
    byte bVar18;
    char cVar19;
    longlong lVar20;
    longlong lVar21;
    undefined1 auStackY_598[32];
    char local_568;
    char local_566;
    char acStack_562[5];
    char acStack_55d[4];
    undefined1 local_559;
    uint local_558;
    char *local_550;
    uint local_548;
    undefined1 *local_540;
    undefined *local_538;
    undefined *puStack_530;
    undefined8 local_528;
    undefined1(*local_520)[16];
    undefined1(*local_518)[16];
    undefined1 local_510;
    undefined *local_508;
    longlong *local_500;
    undefined8 local_4f8[2];
    undefined1 local_4e8;
    undefined8 local_4e0[3];
    longlong local_4c8;
    longlong lStack_4c0;
    longlong local_4b8;
    undefined **ppuStack_4b0;
    longlong local_4a8;
    longlong lStack_4a0;
    longlong local_498;
    longlong lStack_490;
    longlong local_488;
    longlong lStack_480;
    longlong local_478;
    longlong lStack_470;
    longlong local_468;
    longlong lStack_460;
    longlong local_458;
    longlong lStack_450;
    float local_448[64];
    float local_348[64];
    undefined8 local_248[32];
    undefined8 local_148[32];
    ulonglong local_48;

    local_48 = DAT_18125eaa8 ^ (ulonglong)auStackY_598;
    iVar15 = 0;
    if (*(longlong *)(param_1 + 0x98) != 0)
    {
        iVar15 = *(int *)(*(longlong *)(param_1 + 0x98) + 0xa0bc);
    }
    if (((char)param_2[2] == '\0') ||
        ((iVar15 != -1 && (*(char *)(param_2[3] + 0x10 + (longlong)iVar15 * 0x18) == '\0'))))
    {
        local_566 = '\0';
    }
    else
    {
        local_566 = '\x01';
    }
    lVar16 = *(longlong *)(param_1 + 0x90);
    acStack_562[2] = *(undefined1 *)(lVar16 + 0xc81c);
    acStack_562[3] = *(undefined1 *)(lVar16 + 0xc864);
    acStack_562[4] = *(undefined1 *)(lVar16 + 0xc8ac);
    acStack_55d[1] = *(undefined1 *)(lVar16 + 0x9dc4);
    acStack_55d[2] = *(undefined1 *)(lVar16 + 0xa1c4);
    acStack_55d[3] = *(undefined1 *)(lVar16 + 0xa5c4);
    local_559 = *(undefined1 *)(lVar16 + 0xa9c4);
    ppuVar9 = &local_538;
    lVar16 = 2;
    do
    {
        FUN_180ca31f0(ppuVar9);
        ppuVar9 = ppuVar9 + 3;
        lVar16 = lVar16 + -1;
    } while (lVar16 != 0);
    local_538 = &DAT_181296040;
    puStack_530 = &DAT_181296040;
    local_520 = (undefined1(*)[16]) & DAT_181296040;
    local_518 = (undefined1(*)[16]) & DAT_181296040;
    FUN_180ca31e0(local_4f8, &DAT_181296040, &DAT_181296040);
    local_4e8 = 1;
    if (iVar15 == -1)
    {
        puVar13 = local_4f8;
    }
    else
    {
        puVar13 = (undefined8 *)(param_2[3] + (longlong)iVar15 * 0x18);
    }
    local_538 = (undefined *)*puVar13;
    puStack_530 = (undefined *)puVar13[1];
    local_528 = puVar13[2];
    local_520 = (undefined1(*)[16])(param_1 + 0x4a8);
    local_518 = (undefined1(*)[16])(param_1 + 0x5a8);
    uVar17 = (longlong)(int)param_2[5] << 2;
    if ((char)param_2[2] == '\0')
    {
        FUN_181030490((undefined8 *)local_520, (undefined8 *)*param_2, uVar17);
        FUN_181030490((undefined8 *)local_518, (undefined8 *)param_2[1], (longlong)(int)param_2[5] << 2);
    }
    else
    {
        FUN_181030b40(local_520, 0, uVar17);
        FUN_181030b40(local_518, 0, (longlong)(int)param_2[5] << 2);
        local_510 = 1;
    }
    if ((*(char *)(param_1 + 0x12b0) == '\0') || (local_566 == '\0'))
    {
        *(undefined1 *)(param_1 + 0x12b0) = 0;
        cVar19 = '\0';
        local_568 = '\0';
        lVar20 = 0;
        pcVar14 = acStack_55d + 1;
        local_550 = pcVar14;
        lVar21 = 0;
        lVar16 = 4;
        do
        {
            if (*pcVar14 != '\0')
            {
                iVar15 = 0;
                local_550 = pcVar14;
                lVar10 = FUN_180c8b9c0(*(longlong *)(param_1 + 0x90) + 0xa090 + lVar21);
                if (0 < (int)lVar10)
                {
                    do
                    {
                        FUN_180c8b9f0(*(longlong *)(param_1 + 0x90) + 0xa090 + lVar21, &local_508, iVar15);
                        FUN_180ca0d50((longlong)local_508, (longlong)param_2);
                        plVar12 = local_500;
                        if (local_500 != (longlong *)0x0)
                        {
                            LOCK();
                            plVar1 = local_500 + 1;
                            lVar10 = *plVar1;
                            *(int *)plVar1 = (int)*plVar1 + -1;
                            UNLOCK();
                            if ((int)lVar10 == 1)
                            {
                                (**(code **)(*local_500 + 8))(local_500);
                                LOCK();
                                piVar2 = (int *)((longlong)plVar12 + 0xc);
                                iVar3 = *piVar2;
                                *piVar2 = *piVar2 + -1;
                                UNLOCK();
                                if (iVar3 == 1)
                                {
                                    (**(code **)(*plVar12 + 0x10))(plVar12);
                                }
                            }
                        }
                        iVar15 = iVar15 + 1;
                        lVar10 = FUN_180c8b9c0(*(longlong *)(param_1 + 0x90) + 0xa090 + lVar21);
                        pcVar14 = local_550;
                    } while (iVar15 < (int)lVar10);
                }
                if ((local_568 == '\0') &&
                    (*(char *)(*(longlong *)(param_1 + 0x90) + 0x9f74 + lVar20) == '\0'))
                {
                    cVar19 = '\0';
                    local_568 = cVar19;
                }
                else
                {
                    cVar19 = '\x01';
                    local_568 = cVar19;
                }
            }
            lVar21 = lVar21 + 0x400;
            pcVar14 = pcVar14 + 1;
            local_550 = pcVar14;
            lVar20 = lVar20 + 0x400;
            lVar16 = lVar16 + -1;
        } while (lVar16 != 0);
        bVar7 = false;
        uVar17 = CONCAT71((int7)((ulonglong)param_4 >> 8), 1);
        local_558 = (uint)uVar17;
        bVar6 = false;
        local_548 = 0;
        lVar16 = 1;
        local_508 = (undefined *)0x400;
        local_550 = (char *)(param_1 + 0x71c);
        local_540 = (undefined1 *)(param_1 + 0x6a8);
        bVar5 = false;
        do
        {
            uVar8 = local_548;
            bVar18 = (byte)uVar17;
            if ((!bVar5) && (puVar11 = local_508, lVar20 = lVar16, lVar16 < 4))
            {
                do
                {
                    if (acStack_562[lVar20 + 1] == '\0')
                        break;
                    if (((acStack_55d[lVar16] != '\0') &&
                         (puVar11[*(longlong *)(param_1 + 0x90) + 0x9f2c] == '\0')) &&
                        ((cVar19 == '\0' || (puVar11[*(longlong *)(param_1 + 0x90) + 0x9f74] != '\0'))))
                    {
                        bVar6 = true;
                        break;
                    }
                    lVar20 = lVar20 + 1;
                    puVar11 = puVar11 + 0x400;
                } while ((longlong)puVar11 < 0x1000);
            }
            if (acStack_55d[lVar16] != '\0')
            {
                if (bVar18 != 0)
                {
                    uVar17 = (longlong)(int)param_2[5] << 2;
                    FUN_181030490(local_248, (undefined8 *)*param_2, uVar17);
                    FUN_181030490(local_148, (undefined8 *)param_2[1], uVar17);
                    local_558 = local_558 & 0xffffff00;
                }
                if (((uVar8 == 0) || (acStack_562[lVar16] == '\0')) &&
                    ((2 < uVar8 || (acStack_562[lVar16 + 1] == '\0'))))
                {
                    bVar4 = false;
                }
                else
                {
                    bVar4 = true;
                }
                uVar17 = (longlong)(int)param_2[5] << 2;
                FUN_181030490((undefined8 *)local_448, local_248, uVar17);
                FUN_181030490((undefined8 *)local_348, local_148, uVar17);
                local_4c8 = *param_2;
                lStack_4c0 = param_2[1];
                local_4b8 = param_2[2];
                ppuStack_4b0 = (undefined **)param_2[3];
                local_4a8 = param_2[4];
                lStack_4a0 = param_2[5];
                local_498 = param_2[6];
                lStack_490 = param_2[7];
                local_488 = param_2[8];
                lStack_480 = param_2[9];
                local_478 = param_2[10];
                lStack_470 = param_2[0xb];
                local_468 = param_2[0xc];
                lStack_460 = param_2[0xd];
                local_458 = param_2[0xe];
                lStack_450 = param_2[0xf];
                plVar12 = FUN_180ca31e0(local_4e0, local_448, local_348);
                local_4c8 = *plVar12;
                lStack_4c0 = plVar12[1];
                local_4b8 = CONCAT71((int7)((ulonglong)plVar12[2] >> 8), local_566);
                ppuStack_4b0 = &local_538;
                if (((bVar5) || (bVar6)) && (bVar4))
                {
                    cVar19 = '\0';
                }
                else
                {
                    cVar19 = '\x01';
                }
                envelope(local_540, &local_4c8, local_568, cVar19);
                cVar19 = '\0';
                if (*local_550 != '\0')
                {
                    cVar19 = local_566;
                }
                local_566 = cVar19;
                if (bVar7)
                {
                    iVar15 = 0;
                    if (0 < (int)param_2[5])
                    {
                        lVar20 = 0;
                        do
                        {
                            *(float *)(*param_2 + lVar20) =
                                *(float *)((longlong)local_448 + lVar20) + *(float *)(*param_2 + lVar20);
                            *(float *)(lVar20 + param_2[1]) =
                                *(float *)((longlong)local_348 + lVar20) + *(float *)(lVar20 + param_2[1]);
                            iVar15 = iVar15 + 1;
                            lVar20 = lVar20 + 4;
                        } while (iVar15 < (int)param_2[5]);
                    }
                }
                else
                {
                    FUN_181030490((undefined8 *)*param_2, (undefined8 *)local_448,
                                  (longlong)(int)param_2[5] << 2);
                    FUN_181030490((undefined8 *)param_2[1], (undefined8 *)local_348,
                                  (longlong)(int)param_2[5] << 2);
                    bVar7 = true;
                }
                bVar5 = true;
                *(char *)(param_2 + 2) = local_566;
                bVar18 = (byte)local_558;
            }
            cVar19 = acStack_562[lVar16 + 1];
            uVar17 = (ulonglong)bVar18;
            if (cVar19 == '\0')
            {
                uVar17 = 1;
            }
            local_558 = (uint)uVar17;
            local_548 = local_548 + 1;
            local_540 = local_540 + 0x300;
            local_508 = local_508 + 0x400;
            lVar16 = lVar16 + 1;
            local_550 = local_550 + 0x300;
            bVar4 = false;
            if (cVar19 != '\0')
            {
                bVar4 = bVar7;
            }
            bVar7 = bVar4;
            bVar4 = false;
            if (cVar19 != '\0')
            {
                bVar4 = bVar5;
            }
            cVar19 = local_568;
            bVar5 = bVar4;
        } while ((int)local_548 < 4);
    }
    else
    {
        lVar16 = param_1 + 0x6a8;
        lVar20 = 4;
        do
        {
            local_4c8 = *param_2;
            lStack_4c0 = param_2[1];
            local_4b8 = param_2[2];
            local_4a8 = param_2[4];
            lStack_4a0 = param_2[5];
            local_498 = param_2[6];
            lStack_490 = param_2[7];
            local_488 = param_2[8];
            lStack_480 = param_2[9];
            local_478 = param_2[10];
            lStack_470 = param_2[0xb];
            local_468 = param_2[0xc];
            lStack_460 = param_2[0xd];
            local_458 = param_2[0xe];
            lStack_450 = param_2[0xf];
            ppuStack_4b0 = &local_538;
            ppuVar9 = &local_538;
            do
            {
                *(undefined1 *)(ppuVar9 + 2) = 1;
                ppuVar9 = ppuVar9 + 3;
            } while (ppuVar9 != &local_508);
            FUN_1808137b0(lVar16, &local_4c8);
            lVar16 = lVar16 + 0x300;
            lVar20 = lVar20 + -1;
        } while (lVar20 != 0);
    }
    for (plVar12 = (longlong *)(param_1 + 0x120); plVar12 != (longlong *)(param_1 + 0x1c0);
         plVar12 = plVar12 + 10)
    {
        FUN_1808140d0(plVar12, (longlong)&local_538, 2, (int)param_2[5], (char)param_2[0xc]);
    }
    for (plVar12 = (longlong *)(param_1 + 0x1c0); plVar12 != (longlong *)(param_1 + 0x280);
         plVar12 = plVar12 + 0xc)
    {
        FUN_180814c90(plVar12, (longlong)&local_538, 2, (int)param_2[5], (char)param_2[0xc]);
    }
    for (plVar12 = (longlong *)(param_1 + 0x280); plVar12 != (longlong *)(param_1 + 0x2a8);
         plVar12 = plVar12 + 5)
    {
        FUN_180817380(plVar12, (longlong)&local_538, 2, (int)param_2[5], (longlong)param_2,
                      (char)param_2[0xc]);
    }
    *(char *)(param_1 + 0x12b0) = local_566;
    FUN_18100c1e0(local_48 ^ (ulonglong)auStackY_598);
    return;
}
