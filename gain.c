
void gain(longlong param_1, longlong *param_2)

{
    longlong lVar1;
    uint uVar2;
    ulonglong uVar3;
    ulonglong uVar4;
    float fVar5;
    float fVar6;
    float fVar7;

    lVar1 = *(longlong *)(param_1 + 0x90);
    if (*(int *)(lVar1 + 0x9dc4) == 1)
    {
        fVar5 = *(float *)(lVar1 + 0x9e18) + *(float *)(lVar1 + 0x9e18);
    }
    else
    {
        fVar5 = *(float *)(lVar1 + 0x9e0c);
    }
    lVar1 = param_2[5];
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0x9c) = 0;
    if (*(char *)(param_1 + 0xb0) == '\0')
    {
        fVar7 = *(float *)(param_1 + 0xa8);
        if ((fVar5 - fVar7 <= -1e-15) || (1e-15 <= fVar5 - fVar7))
        {
            fVar6 = 1.0 / (float)(int)lVar1;
        }
        else
        {
            fVar6 = 0.0;
            fVar7 = fVar5;
        }
    }
    else
    {
        *(undefined1 *)(param_1 + 0xb0) = 0;
        fVar6 = 0.0;
        fVar7 = fVar5;
    }
    *(float *)(param_1 + 0xac) = fVar7;
    *(float *)(param_1 + 0xa4) = fVar7;
    *(float *)(param_1 + 0xa8) = fVar5;
    *(float *)(param_1 + 0xa0) = fVar6;
    uVar4 = uVar3;
    if (0 < (int)param_2[5])
    {
        do
        {
            fVar5 = *(float *)(param_1 + 0x9c) + 1.0;
            uVar2 = (int)uVar3 + 1;
            uVar3 = (ulonglong)uVar2;
            *(float *)(param_1 + 0x9c) = fVar5;
            fVar5 = fVar5 * *(float *)(param_1 + 0xa0);
            fVar5 = (1.0 - fVar5) * *(float *)(param_1 + 0xa4) + fVar5 * *(float *)(param_1 + 0xa8);
            *(float *)(param_1 + 0xac) = fVar5;
            fVar5 = *(float *)(uVar4 + *param_2) * fVar5;
            *(float *)(uVar4 + *param_2) = fVar5;
            *(float *)(param_1 + 0xc0) =
                (fVar5 * fVar5 - *(float *)(param_1 + 0xc0)) * *(float *)(param_1 + 0xbc) +
                *(float *)(param_1 + 0xc0);
            fVar5 = *(float *)(uVar4 + param_2[1]) * *(float *)(param_1 + 0xac);
            *(float *)(uVar4 + param_2[1]) = fVar5;
            *(float *)(param_1 + 0xd0) =
                (fVar5 * fVar5 - *(float *)(param_1 + 0xd0)) * *(float *)(param_1 + 0xcc) +
                *(float *)(param_1 + 0xd0);
            uVar4 = uVar4 + 4;
        } while ((int)uVar2 < (int)param_2[5]);
    }
    FUN_180afe3a0(*(longlong *)(param_1 + 0x90), *(undefined4 *)(param_1 + 0xc0));
    FUN_180afe420(*(longlong *)(param_1 + 0x90), *(undefined4 *)(param_1 + 0xd0));
    return;
}