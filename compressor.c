
void compressor(longlong param_1, longlong *param_2)

{
    float fVar1;
    int iVar2;
    int iVar3;
    longlong lVar4;
    longlong lVar5;
    float *pfVar6;
    float *pfVar7;
    uint uVar8;
    longlong *plVar9;
    float fVar10;
    float fVar11;
    ulonglong uVar12;
    ulonglong uVar13;
    ulonglong uVar14;
    ulonglong uVar15;
    ulonglong uVar16;
    ulonglong uVar17;
    float fVar18;
    float fVar19;
    float fVar20;
    float local_res8[2];
    float local_res10[2];

    lVar4 = *(longlong *)(param_1 + 0x90);
    iVar2 = *(int *)(lVar4 + 0x9e54);
    fVar1 = *(float *)(lVar4 + 0x9ee4);
    (**(code **)(*(longlong *)(lVar4 + 0xa098) + 0x60))((longlong *)(lVar4 + 0xa098), *(undefined4 *)(lVar4 + 0x9ea8));
    local_res8[0] = 1.0 / *(float *)(param_1 + 0x98);
    uVar12 = FUN_18103fd60();
    uVar13 = FUN_18103fd60();
    if (iVar2 == 0)
    {
        *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_1 + 0xc0);
    }
    else
    {
        *(undefined4 *)(param_1 + 0xa8) = 0x3ba3d70a;
        if (iVar2 == 2)
        {
            fVar10 = 0.0;
        }
        else
        {
            fVar10 = 0.002;
        }
        if (9.536743e-07 < ABS(*(float *)(param_1 + 0xb0) - fVar10))
        {
            *(float *)(param_1 + 0xb0) = fVar10;
            if (fVar10 <= 0.0)
            {
                *(undefined4 *)(param_1 + 0xb8) = 0x3f800000;
            }
            else
            {
                uVar14 = FUN_18103fd60();
                *(float *)(param_1 + 0xb8) = 1.0 - (float)uVar14;
            }
        }
    }
    lVar4 = *(longlong *)(param_1 + 0x90);
    uVar15 = FUN_18103fd60();
    lVar5 = param_2[5];
    uVar16 = FUN_18103fd60();
    fVar10 = local_res8[0];
    uVar14 = 0;
    fVar18 = (float)uVar16;
    *(undefined4 *)(param_1 + 0xe8) = 0;
    fVar19 = 0.0;
    if (*(char *)(param_1 + 0xfc) == '\0')
    {
        fVar20 = *(float *)(param_1 + 0xf4);
        if ((fVar18 - fVar20 <= -1e-15) || (1e-15 <= fVar18 - fVar20))
        {
            *(float *)(param_1 + 0xf0) = fVar20;
            fVar19 = 1.0 / (float)(int)lVar5;
            *(float *)(param_1 + 0xf8) = fVar20;
        }
        else
        {
            *(float *)(param_1 + 0xf0) = fVar18;
            fVar19 = 0.0;
            *(float *)(param_1 + 0xf8) = fVar18;
        }
    }
    else
    {
        *(float *)(param_1 + 0xf8) = fVar18;
        *(float *)(param_1 + 0xf0) = fVar18;
        *(undefined1 *)(param_1 + 0xfc) = 0;
    }
    *(float *)(param_1 + 0xf4) = fVar18;
    *(float *)(param_1 + 0xec) = fVar19;
    iVar3 = *(int *)(lVar4 + 0xa118);
    plVar9 = param_2;
    if (-1 < iVar3)
    {
        plVar9 = (longlong *)(param_2[3] + (longlong)iVar3 * 0x18);
    }
    uVar16 = uVar14;
    if (0 < (int)param_2[5])
    {
        do
        {
            lVar4 = *plVar9;
            fVar18 = *(float *)(param_1 + 0xe8) + 1.0;
            *(float *)(param_1 + 0xe8) = fVar18;
            fVar18 = fVar18 * *(float *)(param_1 + 0xec);
            *(float *)(param_1 + 0xf8) =
                (1.0 - fVar18) * *(float *)(param_1 + 0xf0) + fVar18 * *(float *)(param_1 + 0xf4);
            fVar18 = *(float *)(uVar16 + lVar4);
            fVar19 = *(float *)(uVar16 + plVar9[1]);
            if (iVar2 == 0)
            {
                fVar20 = *(float *)(param_1 + 0xa8);
                fVar18 = (fVar19 * fVar19 + fVar18 * fVar18) * 0.5;
                if (fVar18 <= 9.536743e-07)
                {
                    fVar18 = 9.536743e-07;
                }
                fVar20 = (fVar18 / fVar20 - fVar20) * *(float *)(param_1 + 0xa4) + fVar20;
                *(float *)(param_1 + 0xa8) = fVar20;
            }
            else
            {
                local_res8[0] = ABS(fVar18);
                fVar20 = *(float *)(param_1 + 0xc4);
                pfVar7 = local_res8;
                if (ABS(fVar18) <= ABS(fVar19))
                {
                    pfVar7 = local_res10;
                }
                local_res10[0] = ABS(fVar19);
                pfVar6 = (float *)(param_1 + 0xc0);
                if (*(float *)(param_1 + 0xc0) < *pfVar7)
                {
                    pfVar6 = pfVar7;
                }
                if (*pfVar6 <= fVar20)
                {
                    fVar18 = *(float *)(param_1 + 0xbc);
                }
                else
                {
                    fVar18 = *(float *)(param_1 + 0xb8);
                }
                fVar20 = (*pfVar6 - fVar20) * fVar18 + fVar20;
                *(float *)(param_1 + 0xc4) = fVar20;
            }
            fVar18 = 1.0;
            if (fVar1 < fVar20)
            {
                uVar17 = FUN_18103fd60();
                fVar18 = (float)uVar17 * (float)uVar15;
            }
            fVar19 = *(float *)(param_1 + 0xe4);
            fVar11 = (float)uVar13;
            if (fVar18 < fVar19)
            {
                fVar11 = (float)uVar12;
            }
            fVar19 = (fVar18 - fVar19) * (1.0 - fVar11) + fVar19;
            *(float *)(param_1 + 0xe4) = fVar19;
            fVar19 = fVar19 * *(float *)(param_1 + 0xf8);
            *(float *)(*param_2 + uVar16) = fVar19 * *(float *)(*param_2 + uVar16);
            *(float *)(param_2[1] + uVar16) = fVar19 * *(float *)(param_2[1] + uVar16);
            lVar4 = *(longlong *)(param_1 + 0x90);
            fVar18 = fVar20;
            if (fVar20 <= *(float *)(lVar4 + 0x9fbc))
            {
                fVar19 = *(float *)(param_1 + 0x100);
                if (fVar19 < 0.5)
                {
                    fVar18 = *(float *)(lVar4 + 0x9fbc);
                }
            }
            else
            {
                fVar19 = 0.0;
            }
            *(float *)(param_1 + 0x100) = fVar19 + fVar10;
            fVar19 = *(float *)(param_1 + 0xe0);
            if (fVar18 <= fVar19)
            {
                fVar11 = *(float *)(param_1 + 0xd8);
            }
            else
            {
                fVar11 = *(float *)(param_1 + 0xd4);
            }
            fVar19 = (fVar18 - fVar19) * fVar11 + fVar19;
            *(float *)(param_1 + 0xe0) = fVar19;
            *(float *)(lVar4 + 0x9fbc) = fVar19;
            if (*(char *)(lVar4 + 0x9ffb) == '\0')
            {
                local_res8[0] = *(float *)(lVar4 + 0x9fb8);
                *(undefined1 *)(lVar4 + 0x9ffb) = 1;
                lVar4 = *(longlong *)(lVar4 + 0xa128);
                pfVar7 = *(float **)(lVar4 + 0x30);
                if (pfVar7 == *(float **)(lVar4 + 0x38))
                {
                    FUN_1803ded20((longlong *)(lVar4 + 0x28), (undefined8 *)pfVar7, local_res8);
                }
                else
                {
                    *pfVar7 = local_res8[0];
                    *(longlong *)(lVar4 + 0x30) = *(longlong *)(lVar4 + 0x30) + 4;
                }
            }
            lVar4 = *(longlong *)(param_1 + 0x90);
            *(float *)(lVar4 + 0x9f74) = fVar20;
            if (*(char *)(lVar4 + 0x9fb3) == '\0')
            {
                local_res8[0] = *(float *)(lVar4 + 0x9f70);
                *(undefined1 *)(lVar4 + 0x9fb3) = 1;
                lVar4 = *(longlong *)(lVar4 + 0xa128);
                pfVar7 = *(float **)(lVar4 + 0x30);
                if (pfVar7 == *(float **)(lVar4 + 0x38))
                {
                    FUN_1803ded20((longlong *)(lVar4 + 0x28), (undefined8 *)pfVar7, local_res8);
                }
                else
                {
                    *pfVar7 = local_res8[0];
                    *(longlong *)(lVar4 + 0x30) = *(longlong *)(lVar4 + 0x30) + 4;
                }
            }
            lVar4 = *(longlong *)(param_1 + 0x90);
            local_res8[0] = *(float *)(param_1 + 0xe4);
            *(float *)(lVar4 + 0xa004) = local_res8[0];
            if (*(char *)(lVar4 + 0xa043) == '\0')
            {
                local_res8[0] = *(float *)(lVar4 + 0xa000);
                *(undefined1 *)(lVar4 + 0xa043) = 1;
                lVar4 = *(longlong *)(lVar4 + 0xa128);
                pfVar7 = *(float **)(lVar4 + 0x30);
                if (pfVar7 == *(float **)(lVar4 + 0x38))
                {
                    FUN_1803ded20((longlong *)(lVar4 + 0x28), (undefined8 *)pfVar7, local_res8);
                }
                else
                {
                    *pfVar7 = local_res8[0];
                    *(longlong *)(lVar4 + 0x30) = *(longlong *)(lVar4 + 0x30) + 4;
                }
            }
            uVar8 = (int)uVar14 + 1;
            uVar14 = (ulonglong)uVar8;
            uVar16 = uVar16 + 4;
        } while ((int)uVar8 < (int)param_2[5]);
    }
    return;
}
