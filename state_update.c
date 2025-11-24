
void state_update(longlong param_1)

{
    FUN_180c96590(*(longlong **)(param_1 + 0x90));
    if (*(int *)((longlong) * (longlong **)(param_1 + 0x90) + 0x74) != *(int *)(param_1 + 0x9c))
    {
        (**(code **)(**(longlong **)(param_1 + 0x90) + 0x50))();
        *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x74);
    }
    return;
}

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_180c96590(longlong *param_1)

{
    longlong *plVar1;
    uint *puVar2;
    undefined1(*pauVar3)[16];
    undefined1(*pauVar4)[16];
    ushort uVar5;
    int iVar6;
    uint uVar7;
    code *pcVar8;
    int *piVar9;
    int *piVar10;
    longlong *plVar11;
    longlong lVar12;
    longlong lVar13;
    short sVar14;
    longlong lVar15;
    uint *puVar16;
    ulonglong uVar17;
    longlong *plVar18;
    int *piVar19;
    undefined1 *puVar20;
    undefined1 *puVar21;
    uint *puVar22;
    longlong *plVar23;
    int iVar24;
    uint uVar25;
    uint uVar26;
    uint *puVar27;
    undefined8 uStack_a0;
    undefined1 auStack_98[32];
    int local_78;
    uint local_74;
    undefined4 local_70;
    undefined1 local_6c;
    uint local_68[2];
    uint *local_60;
    undefined1(*local_58)[16];
    uint *local_50;
    longlong local_48;
    longlong *local_40;
    ulonglong local_38;

    puVar20 = auStack_98;
    local_38 = DAT_18125eaa8 ^ (ulonglong)&local_78;
    puVar21 = auStack_98;
    if ((char)param_1[0xe] != '\0')
    {
        iVar24 = (int)(param_1[2] - param_1[1] >> 3);
        if (iVar24 != 0)
        {
            uVar17 = (longlong)iVar24 + 0xf;
            if (uVar17 <= (ulonglong)(longlong)iVar24)
            {
                uVar17 = 0xffffffffffffff0;
            }
            uStack_a0 = 0x180c9660c;
            lVar12 = -(uVar17 & 0xfffffffffffffff0);
            pauVar3 = (undefined1(*)[16])((longlong)&local_78 + lVar12);
            *(undefined8 *)(auStack_98 + lVar12 + -8) = 0x180c96621;
            FUN_181030b40(pauVar3, 0, (longlong)iVar24);
            param_1[9] = param_1[8];
            iVar24 = (int)(param_1[2] - param_1[1] >> 3);
            uVar17 = (longlong)iVar24 + 0xf;
            if (uVar17 <= (ulonglong)(longlong)iVar24)
            {
                uVar17 = 0xffffffffffffff0;
            }
            *(undefined8 *)(auStack_98 + lVar12 + -8) = 0x180c96654;
            lVar13 = -(uVar17 & 0xfffffffffffffff0);
            puVar20 = auStack_98 + lVar13 + lVar12;
            pauVar4 = (undefined1(*)[16])((longlong)&local_78 + lVar13 + lVar12);
            local_58 = pauVar4;
            *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c9666d;
            FUN_181030b40(pauVar4, 0, (longlong)iVar24);
            if (param_1 + 0xf != param_1 + 0x333)
            {
                plVar18 = param_1 + 0x12;
                do
                {
                    sVar14 = *(short *)((longlong)plVar18 + -0x14);
                    if (sVar14 == 0)
                        break;
                    if (sVar14 == -3)
                    {
                        pcVar8 = *(code **)(*param_1 + 0x50);
                        *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c966ac;
                        lVar15 = (*pcVar8)(param_1);
                        uVar26 = *(uint *)((ulonglong) * (ushort *)((longlong)plVar18 + -0x12) * 0x148 + 0x90 +
                                           lVar15);
                    LAB_180c966bf:
                        *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c966cd;
                        FUN_180c961a0((longlong)param_1, 0.0, 0, uVar26);
                    }
                    else
                    {
                        if (sVar14 == -1)
                        {
                            uVar26 = (uint) * (ushort *)((longlong)plVar18 + -0x12);
                            goto LAB_180c966bf;
                        }
                        lVar15 = plVar18[-1];
                        if (lVar15 != 0)
                        {
                            uVar5 = *(ushort *)((longlong)plVar18 + -0x12);
                            *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c96703;
                            FUN_180c9d6e0(lVar15, 0, 0, (uint)uVar5);
                            plVar23 = (longlong *)*plVar18;
                            plVar18[-1] = 0;
                            *plVar18 = 0;
                            if (plVar23 != (longlong *)0x0)
                            {
                                LOCK();
                                plVar11 = plVar23 + 1;
                                lVar15 = *plVar11;
                                *(int *)plVar11 = (int)*plVar11 + -1;
                                UNLOCK();
                                if ((int)lVar15 == 1)
                                {
                                    pcVar8 = *(code **)(*plVar23 + 8);
                                    *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c9672d;
                                    (*pcVar8)(plVar23);
                                    LOCK();
                                    piVar9 = (int *)((longlong)plVar23 + 0xc);
                                    iVar24 = *piVar9;
                                    *piVar9 = *piVar9 + -1;
                                    UNLOCK();
                                    if (iVar24 == 1)
                                    {
                                        pcVar8 = *(code **)(*plVar23 + 0x10);
                                        *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c96745;
                                        (*pcVar8)(plVar23);
                                    }
                                }
                            }
                        }
                    }
                    plVar23 = plVar18 + 1;
                    plVar18 = plVar18 + 4;
                } while (plVar23 != param_1 + 0x333);
            }
            plVar18 = param_1 + 8;
            iVar24 = 0;
            piVar9 = (int *)param_1[0xc];
            piVar19 = (int *)param_1[0xb];
            local_78 = 0;
            if (piVar19 != piVar9)
            {
                puVar22 = (uint *)((longlong)param_1 + 0x7c);
                do
                {
                    iVar6 = *piVar19;
                    if ((*pauVar4)[iVar6] == '\0')
                    {
                        if ((*pauVar3)[iVar6] == '\0')
                        {
                            piVar10 = (int *)param_1[9];
                            if (piVar10 == (int *)param_1[10])
                            {
                                *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c967bf;
                                FUN_1803ded20(plVar18, (undefined8 *)piVar10, piVar19);
                                iVar24 = local_78;
                            }
                            else
                            {
                                *piVar10 = iVar6;
                                param_1[9] = param_1[9] + 4;
                            }
                            (*pauVar3)[*piVar19] = 1;
                        }
                        iVar24 = iVar24 + 1;
                        local_60 = (uint *)CONCAT44(local_60._4_4_, 0xfffe);
                        puVar22[-1] = 0xfffe;
                        iVar6 = *piVar19;
                        puVar22[1] = 0xffffffff;
                        local_70 = CONCAT22((short)iVar6, 0xffff);
                        *puVar22 = local_70;
                        puVar22 = puVar22 + 8;
                        local_78 = iVar24;
                        (*pauVar4)[*piVar19] = 1;
                    }
                    piVar19 = piVar19 + 1;
                } while (piVar19 != piVar9);
            }
            iVar24 = 0;
            pcVar8 = *(code **)(*param_1 + 0x50);
            *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c96829;
            puVar16 = (uint *)(*pcVar8)(param_1);
            local_60 = puVar16;
            puVar22 = puVar16 + 0x2008;
            local_50 = puVar22;
            if (puVar16 != puVar22)
            {
                plVar23 = param_1 + (longlong)local_78 * 4 + 0x12;
                puVar27 = puVar16 + 0x13;
                do
                {
                    uVar26 = puVar27[-0x12];
                    uVar7 = *puVar27;
                    local_70 = uVar7;
                    uVar7 = local_70;
                    if (((((short)uVar26 == 0) || (sVar14 = (short)uVar7, sVar14 == 0)) || ((int)uVar26 < 0)) || (uVar25 = uVar7 >> 0x10, (int)uVar7 < 0))
                    {
                    LAB_180c96a4f:
                        iVar24 = iVar24 + 1;
                    }
                    else
                    {
                        if ((short)uVar26 == -1)
                        {
                            *(uint *)(plVar23 + -3) = uVar26;
                            *(uint *)((longlong)plVar23 + -0x14) = uVar7;
                            *(int *)(plVar23 + -2) = iVar24;
                            if (sVar14 == -3)
                            {
                                local_68[0] = puVar16[(ulonglong)uVar25 * 0x52 + 0x24];
                                if ((*pauVar3)[(int)local_68[0]] == '\0')
                                {
                                    puVar22 = (uint *)param_1[9];
                                    if (puVar22 == (uint *)param_1[10])
                                    {
                                        *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c9693d;
                                        FUN_1803ded20(plVar18, (undefined8 *)puVar22, local_68);
                                        (*pauVar3)[(int)local_68[0]] = 1;
                                        uVar7 = local_70;
                                    }
                                    else
                                    {
                                        *puVar22 = local_68[0];
                                        param_1[9] = param_1[9] + 4;
                                        (*pauVar3)[(int)local_68[0]] = 1;
                                        uVar7 = local_70;
                                    }
                                }
                            }
                            else
                            {
                                if (sVar14 == -1)
                                    goto LAB_180c96953;
                                pcVar8 = *(code **)(*param_1 + 0x18);
                                *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c969b1;
                                (*pcVar8)(param_1, &local_48, uVar7 & 0xffff);
                                if (local_40 != (longlong *)0x0)
                                {
                                    LOCK();
                                    *(int *)(local_40 + 1) = (int)local_40[1] + 1;
                                    UNLOCK();
                                }
                                plVar11 = (longlong *)*plVar23;
                                plVar23[-1] = local_48;
                                *plVar23 = (longlong)local_40;
                                if (plVar11 != (longlong *)0x0)
                                {
                                    LOCK();
                                    plVar1 = plVar11 + 1;
                                    lVar15 = *plVar1;
                                    *(int *)plVar1 = (int)*plVar1 + -1;
                                    UNLOCK();
                                    if ((int)lVar15 == 1)
                                    {
                                        pcVar8 = *(code **)(*plVar11 + 8);
                                        *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c969ef;
                                        (*pcVar8)(plVar11);
                                        LOCK();
                                        piVar9 = (int *)((longlong)plVar11 + 0xc);
                                        iVar6 = *piVar9;
                                        *piVar9 = *piVar9 + -1;
                                        UNLOCK();
                                        if (iVar6 == 1)
                                        {
                                            pcVar8 = *(code **)(*plVar11 + 0x10);
                                            *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c96a07;
                                            (*pcVar8)(plVar11);
                                        }
                                    }
                                }
                                plVar11 = local_40;
                                uVar7 = local_70;
                                if (local_40 != (longlong *)0x0)
                                {
                                    LOCK();
                                    plVar1 = local_40 + 1;
                                    lVar15 = *plVar1;
                                    *(int *)plVar1 = (int)*plVar1 + -1;
                                    UNLOCK();
                                    if ((int)lVar15 == 1)
                                    {
                                        pcVar8 = *(code **)(*local_40 + 8);
                                        *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c96a28;
                                        (*pcVar8)(plVar11);
                                        LOCK();
                                        piVar9 = (int *)((longlong)plVar11 + 0xc);
                                        iVar6 = *piVar9;
                                        *piVar9 = *piVar9 + -1;
                                        UNLOCK();
                                        uVar7 = local_70;
                                        if (iVar6 == 1)
                                        {
                                            pcVar8 = *(code **)(*plVar11 + 0x10);
                                            *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c96a40;
                                            (*pcVar8)(plVar11);
                                            uVar7 = local_70;
                                        }
                                    }
                                }
                            }
                        LAB_180c96a40:
                            local_70 = uVar7;
                            local_78 = local_78 + 1;
                            plVar23 = plVar23 + 4;
                            puVar16 = local_60;
                            puVar22 = local_50;
                            goto LAB_180c96a4f;
                        }
                        if (sVar14 != -1)
                            goto LAB_180c96a4f;
                        if ((*local_58)[uVar25] == '\0')
                        {
                            (*local_58)[uVar25] = 1;
                            *(uint *)(plVar23 + -3) = uVar26;
                            *(uint *)((longlong)plVar23 + -0x14) = uVar7;
                            *(int *)(plVar23 + -2) = iVar24;
                        LAB_180c96953:
                            local_70._2_2_ = (ushort)(uVar7 >> 0x10);
                            local_74 = (uint)local_70._2_2_;
                            if ((*pauVar3)[local_70._2_2_] == '\0')
                            {
                                puVar22 = (uint *)param_1[9];
                                local_70 = uVar7;
                                if (puVar22 == (uint *)param_1[10])
                                {
                                    *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c9698f;
                                    FUN_1803ded20(plVar18, (undefined8 *)puVar22, &local_74);
                                    (*pauVar3)[(int)local_74] = 1;
                                    uVar7 = local_70;
                                }
                                else
                                {
                                    *puVar22 = (uint)local_70._2_2_;
                                    param_1[9] = param_1[9] + 4;
                                    uVar26 = (uint)local_70._2_2_;
                                    (*pauVar3)[(int)uVar26] = 1;
                                    uVar7 = local_70;
                                }
                            }
                            goto LAB_180c96a40;
                        }
                    }
                    puVar2 = puVar27 + 0x3f;
                    puVar27 = puVar27 + 0x52;
                } while (puVar2 != puVar22);
            }
            lVar15 = (longlong)local_78;
            *(undefined8 *)(auStack_98 + lVar13 + lVar12 + -8) = 0x180c96a8d;
            FUN_180c95d00(param_1 + 0xf, param_1 + lVar15 * 4 + 0xf,
                          (longlong)(param_1 + lVar15 * 4 + 0xf) - (longlong)(param_1 + 0xf) >> 5, local_6c);
            *(undefined4 *)(lVar15 * 0x20 + 0x7c + (longlong)param_1) = 0;
            *(int *)((longlong)param_1 + 0x74) = *(int *)((longlong)param_1 + 0x74) + 1;
            local_74 = 0;
        }
        *(undefined1 *)(param_1 + 0xe) = 0;
        puVar21 = puVar20;
    }
    uVar17 = local_38 ^ (ulonglong)&local_78;
    *(undefined8 *)(puVar21 + -8) = 0x180c96aa9;
    FUN_18100c1e0(uVar17);
    return;
}
