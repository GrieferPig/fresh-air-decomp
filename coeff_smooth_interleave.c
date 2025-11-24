
void coeff_smooth_interleave(longlong param_1, ulonglong *param_2)

{
    longlong lVar1;
    int iVar2;
    undefined8 uVar3;
    float *pfVar4;
    ulonglong uVar5;
    ulonglong uVar6;
    uint uVar7;
    undefined8 *puVar9;
    longlong *plVar10;
    float fVar11;
    float fVar12;
    undefined8 local_res8;
    float local_res10[2];
    ulonglong uVar8;

    uVar6 = 0;
    if (0 < (int)param_2[5])
    {
        uVar5 = uVar6;
        uVar8 = uVar6;
        puVar9 = (undefined8 *)(param_1 + 0xa0);
        do
        {
            uVar7 = (int)uVar8 + 1;
            uVar8 = (ulonglong)uVar7;
            *puVar9 = CONCAT44(*(undefined4 *)(uVar5 + param_2[1]), *(undefined4 *)(uVar5 + *param_2));
            puVar9[1] = 0;
            uVar5 = uVar5 + 4;
            puVar9 = puVar9 + 2;
        } while ((int)uVar7 < (int)param_2[5]);
    }
    uVar7 = *(int *)(*(longlong *)(param_1 + 0x90) + 0x9ee4) * 2;
    uVar3 = FUN_180b802c0((int *)((longlong) * (int *)(param_1 + 0x12f8) * 800 + 0xca0 + param_1),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x9dc4), uVar7);
    if ((char)uVar3 == '\0')
    {
        iVar2 = *(int *)(param_1 + 0x12f8);
    }
    else
    {
        if (*(char *)(param_1 + 0x12fc) != '\0')
            goto LAB_180b6f1a8;
        *(undefined1 *)(param_1 + 0x12fc) = 1;
        iVar2 = 1 - *(int *)(param_1 + 0x12f8);
        *(int *)(param_1 + 0x12f8) = iVar2;
        *(undefined4 *)(param_1 + 0x1300) = 0;
        *(undefined8 *)(param_1 + 0x12ec) = 0;
        *(undefined8 *)(param_1 + 0x12e4) = 0;
        *(undefined4 *)(param_1 + 0x12e0) = 0;
        *(undefined1 *)(param_1 + 0x12f4) = 0;
    }
    lVar1 = *(longlong *)(param_1 + 0x90);
    FUN_180b7fa80((undefined4 *)((longlong)iVar2 * 800 + 0xca0 + param_1),
                  *(undefined4 *)(lVar1 + 0x9dc4), (ulonglong)uVar7, *(float *)(lVar1 + 0x9e0c),
                  *(float *)(lVar1 + 0x9e54), *(float *)(lVar1 + 0x9e9c), *(float *)(param_1 + 0x98));
LAB_180b6f1a8:
    plVar10 = (longlong *)(param_1 + 0xa0);
    if (*(char *)(param_1 + 0x12fc) == '\0')
    {
        eq_filter((int *)((longlong) * (int *)(param_1 + 0x12f8) * 800 + 0xca0 + param_1), plVar10,
                  (int)param_2[5]);
    }
    else
    {
        fVar12 = (float)(int)param_2[5] / *(float *)(param_1 + 0x98) + *(float *)(param_1 + 0x1300);
        *(float *)(param_1 + 0x1300) = fVar12;
        fVar12 = fVar12 * 10.0;
        FUN_181030490((undefined8 *)(param_1 + 0x4a0), plVar10, (longlong)(int)param_2[5] << 4);
        eq_filter((int *)((longlong) * (int *)(param_1 + 0x12f8) * 800 + 0xca0 + param_1),
                  (undefined8 *)(param_1 + 0x4a0), (int)param_2[5]);
        eq_filter((int *)((longlong)(1 - *(int *)(param_1 + 0x12f8)) * 800 + 0xca0 + param_1), plVar10,
                  (int)param_2[5]);
        local_res10[0] = fVar12;
        local_res8 = (ulonglong)local_res8._4_4_ << 0x20;
        pfVar4 = (float *)&local_res8;
        if (0.0 <= fVar12)
        {
            pfVar4 = local_res10;
        }
        fVar11 = *pfVar4;
        if (1.0 <= fVar11)
        {
            fVar11 = 1.0;
        }
        FUN_1806b0f20((float *)(param_1 + 0x12e0), (longlong)plVar10, param_1 + 0x4a0, (int)param_2[5],
                      fVar11);
        if (1.0 < fVar12)
        {
            *(undefined1 *)(param_1 + 0x12fc) = 0;
            FUN_180b80260((undefined4 *)((longlong)(1 - *(int *)(param_1 + 0x12f8)) * 800 + 0xca0 + param_1));
        }
    }
    uVar5 = uVar6;
    if (0 < (int)param_2[5])
    {
        do
        {
            lVar1 = *plVar10;
            plVar10 = plVar10 + 2;
            uVar8 = param_2[1];
            uVar7 = (int)uVar5 + 1;
            local_res8._0_4_ = (float)lVar1;
            local_res8._4_4_ = (uint)((ulonglong)lVar1 >> 0x20);
            *(float *)(uVar6 + *param_2) = (float)local_res8;
            *(uint *)(uVar6 + uVar8) = local_res8._4_4_;
            uVar6 = uVar6 + 4;
            uVar5 = (ulonglong)uVar7;
            local_res8 = lVar1;
        } while ((int)uVar7 < (int)param_2[5]);
    }
    if ((char)param_2[0xc] != '\0')
    {
        FUN_180ac5230(param_1, param_2);
    }
    return;
}
