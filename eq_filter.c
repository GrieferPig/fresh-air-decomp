
void eq_filter(int *param_1, undefined8 *param_2, int param_3)

{
    float fVar1;
    double dVar2;
    double dVar3;
    undefined1 auVar4[16];
    double dVar5;
    double dVar6;
    double dVar7;
    double dVar8;
    double dVar9;
    double dVar10;
    double dVar11;
    double dVar12;
    undefined8 *puVar13;
    double *pdVar14;
    double *pdVar15;
    int iVar16;
    longlong lVar17;
    float fVar18;
    ulonglong uVar19;
    undefined1 auVar20[16];
    undefined1 auVar21[16];
    float fVar22;
    double dVar23;
    double dVar24;
    double dVar25;
    double dVar26;
    undefined1 in_XMM3[16];
    undefined1 auVar27[16];
    double dVar28;
    undefined1 in_XMM4[16];
    undefined1 auVar29[16];
    double dVar30;
    double local_f8;
    double local_f0;

    uVar19 = FUN_18103fd60();
    iVar16 = 0;
    fVar18 = (float)uVar19;
    param_1[0xbe] = 0;
    fVar22 = 0.0;
    if ((char)param_1[0xc3] == '\0')
    {
        fVar1 = (float)param_1[0xc1];
        in_XMM3 = ZEXT416((uint)fVar1);
        if ((fVar18 - fVar1 <= -1e-15) || (1e-15 <= fVar18 - fVar1))
        {
            param_1[0xc0] = (int)fVar1;
            fVar22 = 1.0 / (float)param_3;
            param_1[0xc2] = (int)fVar1;
        }
        else
        {
            param_1[0xc0] = (int)fVar18;
            fVar22 = 0.0;
            param_1[0xc2] = (int)fVar18;
        }
    }
    else
    {
        param_1[0xc2] = (int)fVar18;
        param_1[0xc0] = (int)fVar18;
        *(undefined1 *)(param_1 + 0xc3) = 0;
    }
    param_1[0xc1] = (int)fVar18;
    param_1[0xbf] = (int)fVar22;
    if (0 < *param_1)
    {
        pdVar14 = (double *)(param_1 + 0xc);
        pdVar15 = (double *)(param_1 + 0x84);
        do
        {
            dVar10 = 0.0;
            dVar9 = NAN;
            dVar2 = pdVar15[-1];
            dVar28 = *pdVar15;
            auVar29._0_8_ = (-1.0 - dVar2) - dVar28;
            auVar29._8_8_ = 0;
            if (auVar29._0_8_ <= 0.0)
            {
                dVar11 = SQRT(-auVar29._0_8_);
                dVar30 = 0.0;
            }
            else
            {
                auVar29 = sqrtpd(in_XMM4, auVar29);
                dVar30 = auVar29._0_8_;
                dVar11 = dVar10;
            }
            auVar20._0_8_ = (dVar2 - 1.0) - dVar28;
            auVar20._8_8_ = 0;
            if (auVar20._0_8_ <= 0.0)
            {
                dVar23 = SQRT(-auVar20._0_8_);
                dVar25 = 0.0;
            }
            else
            {
                auVar29 = sqrtpd(in_XMM3, auVar20);
                dVar25 = auVar29._0_8_;
                dVar23 = 0.0;
            }
            if (((ulonglong)ABS(dVar25) < 0x7ff0000000000001) &&
                ((ulonglong)ABS(dVar23) < 0x7ff0000000000001))
            {
                if (ABS(dVar25) <= ABS(dVar23))
                {
                    if (dVar23 != 0.0)
                    {
                        dVar24 = dVar25 * (dVar25 / dVar23) + dVar23;
                        if (((ulonglong)ABS(dVar24) < 0x7ff0000000000001) && (dVar24 != 0.0))
                        {
                            dVar9 = (dVar11 + dVar30 * (dVar25 / dVar23)) / dVar24;
                        }
                    }
                }
                else
                {
                    dVar24 = dVar23 * (dVar23 / dVar25) + dVar25;
                    if (((ulonglong)ABS(dVar24) < 0x7ff0000000000001) && (dVar24 != 0.0))
                    {
                        dVar9 = (dVar11 * (dVar23 / dVar25) + dVar30) / dVar24;
                    }
                }
            }
            dVar24 = pdVar15[-4];
            dVar3 = pdVar15[-2];
            in_XMM3._0_8_ = 1.0 / (dVar30 * dVar25 - dVar23 * dVar11);
            in_XMM3._8_8_ = 0.0;
            dVar11 = ((dVar24 - pdVar15[-3]) + dVar3) / ((1.0 - dVar2) + dVar28);
            dVar2 = (dVar24 + pdVar15[-3] + dVar3) / (dVar2 + 1.0 + dVar28);
            dVar30 = (dVar28 - 1.0) * in_XMM3._0_8_;
            dVar28 = (dVar24 - dVar3) * -2.0 * in_XMM3._0_8_;
            if (*(char *)(pdVar14 + 5) == '\0')
            {
                dVar23 = 1.0 / (double)param_3;
                local_f8 = (dVar30 - pdVar14[1]) * dVar23;
                dVar28 = (dVar28 - pdVar14[3]) * dVar23;
                dVar10 = (dVar9 - *pdVar14) * dVar23;
                dVar2 = (dVar2 - pdVar14[4]) * dVar23;
                dVar23 = (dVar11 - pdVar14[2]) * dVar23;
                local_f0 = dVar28;
            }
            else
            {
                *(undefined1 *)(pdVar14 + 5) = 0;
                *pdVar14 = dVar9;
                pdVar14[1] = dVar30;
                pdVar14[2] = dVar11;
                pdVar14[3] = dVar28;
                pdVar14[4] = dVar2;
                local_f8 = 0.0;
                local_f0 = 0.0;
                dVar2 = dVar10;
                dVar23 = dVar10;
            }
            puVar13 = param_2;
            lVar17 = (longlong)param_3;
            if (0 < param_3)
            {
                do
                {
                    dVar9 = *pdVar14;
                    dVar12 = pdVar14[-4];
                    dVar24 = pdVar14[-3];
                    dVar5 = dVar9 + dVar9;
                    dVar3 = pdVar14[1] + pdVar14[1];
                    dVar26 = dVar3 + dVar9;
                    dVar30 = (double)(float)*puVar13;
                    dVar25 = (double)(float)((ulonglong)*puVar13 >> 0x20);
                    dVar28 = 1.0 / (dVar26 * dVar9 + 1.0);
                    auVar27._8_4_ = SUB84(dVar25, 0);
                    auVar27._0_8_ = dVar30;
                    auVar27._12_4_ = (int)((ulonglong)dVar25 >> 0x20);
                    dVar6 = pdVar14[-2];
                    dVar8 = pdVar14[-1];
                    dVar11 = dVar30 * dVar9 + dVar12;
                    dVar7 = dVar25 * dVar9 + dVar24;
                    in_XMM3._0_8_ = dVar30 - (dVar26 * dVar11 + dVar6) * dVar28;
                    in_XMM3._8_8_ = auVar27._8_8_ - (dVar26 * dVar7 + dVar8) * dVar28;
                    dVar6 = (dVar11 - dVar6 * dVar9) * dVar28 * dVar9 + dVar6;
                    dVar8 = (dVar7 - dVar8 * dVar9) * dVar28 * dVar9 + dVar8;
                    dVar11 = in_XMM3._0_8_ * dVar9 + dVar12;
                    dVar9 = in_XMM3._8_8_ * dVar9 + dVar24;
                    auVar21._8_4_ = SUB84(dVar9, 0);
                    auVar21._0_8_ = dVar11;
                    auVar21._12_4_ = (int)((ulonglong)dVar9 >> 0x20);
                    dVar24 = ((dVar25 - dVar3 * dVar9) - dVar8) * dVar5 + dVar24;
                    auVar4._8_4_ = SUB84(dVar24, 0);
                    auVar4._0_8_ = ((dVar30 - dVar3 * dVar11) - dVar6) * dVar5 + dVar12;
                    auVar4._12_4_ = (int)((ulonglong)dVar24 >> 0x20);
                    *(undefined1(*)[16])(pdVar14 + -4) = auVar4;
                    pdVar14[-2] = dVar11 * dVar5 + pdVar14[-2];
                    pdVar14[-1] = auVar21._8_8_ * dVar5 + pdVar14[-1];
                    *puVar13 = CONCAT44((float)(pdVar14[3] * dVar9 + pdVar14[4] * dVar8 +
                                                pdVar14[2] * in_XMM3._8_8_),
                                        (float)(pdVar14[3] * dVar11 + pdVar14[4] * dVar6 +
                                                pdVar14[2] * in_XMM3._0_8_));
                    puVar13[1] = 0;
                    *pdVar14 = *pdVar14 + dVar10;
                    pdVar14[1] = local_f8 + pdVar14[1];
                    pdVar14[4] = dVar2 + pdVar14[4];
                    pdVar14[3] = local_f0 + pdVar14[3];
                    pdVar14[2] = dVar23 + pdVar14[2];
                    lVar17 = lVar17 + -1;
                    puVar13 = puVar13 + 2;
                } while (lVar17 != 0);
            }
            in_XMM4._8_8_ = 0;
            in_XMM4._0_8_ = dVar28;
            iVar16 = iVar16 + 1;
            pdVar14 = pdVar14 + 10;
            pdVar15 = pdVar15 + 5;
        } while (iVar16 < *param_1);
    }
    return;
}
