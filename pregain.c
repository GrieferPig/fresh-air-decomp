
float FUN_180460b50(longlong param_1)

{
    undefined8 uVar1;

    uVar1 = FUN_181048900();
    return (float)uVar1 - *(float *)(param_1 + 0x18);
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_181048900(void)

{
    float fVar1;
    float fVar2;
    double dVar3;
    undefined1 auVar5[16];
    undefined1 in_ZMM0[64];
    undefined1 auVar7[64];
    undefined1 auVar8[64];
    undefined1 auVar9[64];
    undefined1 auVar10[64];
    undefined1 auVar11[64];
    undefined1 auVar6[16];
    undefined1 auVar12[64];
    undefined1 auVar13[64];
    undefined1 auVar14[64];
    undefined1 auVar15[16];
    double dVar16;
    double dVar17;
    undefined1 auVar18[16];
    uint uVar19;
    undefined8 uVar4;
    undefined1 extraout_var[60];
    undefined1 extraout_var_00[60];
    undefined1 extraout_var_01[60];
    undefined1 extraout_var_02[60];
    undefined1 extraout_var_03[60];
    undefined1 extraout_var_04[60];

    uVar4 = in_ZMM0._0_8_;
    fVar2 = in_ZMM0._0_4_;
    auVar5._8_8_ = in_ZMM0._8_8_;
    if (DAT_1813070f8 == 0)
    {
        fVar1 = ABS(fVar2);
        if ((uint)fVar1 < 0x7f800000)
        {
            dVar16 = (double)fVar2 * 92.33248261689366;
            auVar7._16_48_ = in_ZMM0._16_48_;
            if (8192.0 <= dVar16)
            {
                auVar10._0_4_ = FUN_18105d428(fVar1, INFINITY, 3);
                auVar10._4_60_ = extraout_var_00;
                uVar4 = auVar10._0_8_;
            }
            else
            {
                if (-9600.0 <= dVar16)
                {
                    uVar19 = (uint)dVar16;
                    dVar3 = (double)fVar2 - (double)(int)uVar19 * 0.010830424696249145;
                    dVar16 = auVar5._8_8_ - (double)(int)dVar16 * 0.0;
                    dVar17 = dVar3 * 0.16666666666666666 + 0.5;
                    auVar7._0_8_ = ((dVar3 * dVar3 * dVar17 + dVar3) *
                                        *(double *)(&DAT_181130570 + (ulonglong)(uVar19 & 0x3f) * 8) +
                                    *(double *)(&DAT_181130570 + (ulonglong)(uVar19 & 0x3f) * 8)) *
                                   (double)((ulonglong)(uint)((int)(uVar19 - (uVar19 & 0x3f)) >> 6) + 0x3ff << 0x34);
                    auVar7._8_8_ = ((dVar16 * dVar16 * dVar17 + dVar16) * 0.0 + 0.0) * 0.0;
                    auVar8._4_60_ = auVar7._4_60_;
                    auVar8._0_4_ = (float)auVar7._0_8_;
                    return auVar8._0_8_;
                }
                auVar9._0_4_ = FUN_18105d428(fVar1, 0.0, 2);
                auVar9._4_60_ = extraout_var;
                uVar4 = auVar9._0_8_;
            }
        }
        else if (fVar2 != INFINITY)
        {
            if (fVar2 == -INFINITY)
            {
                return 0;
            }
            auVar11._0_4_ = FUN_18105d428(fVar2, (float)((uint)fVar2 | 0x400000), 1);
            auVar11._4_60_ = extraout_var_01;
            uVar4 = auVar11._0_8_;
        }
    }
    else
    {
        fVar1 = ABS(fVar2);
        if ((uint)fVar1 < 0x7f800000)
        {
            auVar5._0_8_ = (double)fVar2;
            dVar16 = auVar5._0_8_ * 92.33248261689366;
            if (8192.0 <= dVar16)
            {
                auVar13._0_4_ = FUN_18105d428(fVar1, INFINITY, 3);
                auVar13._4_60_ = extraout_var_03;
                uVar4 = auVar13._0_8_;
            }
            else
            {
                if (-9600.0 <= dVar16)
                {
                    auVar18._8_8_ = 0;
                    auVar18._0_8_ = dVar16;
                    auVar18 = vcvtpd2dq_avx(auVar18);
                    auVar15 = vcvtdq2pd_avx(auVar18);
                    auVar15 = vfnmadd231sd_fma(auVar5, auVar15, ZEXT816(0x3f862e42fefa39ef));
                    uVar19 = auVar18._0_4_ & 0x3f;
                    auVar5 = vfmadd213sd_fma(_DAT_18112b310, auVar15, ZEXT816(0x3fe0000000000000));
                    auVar6._8_8_ = 0;
                    auVar6._0_8_ = auVar15._0_8_ * auVar15._0_8_;
                    auVar5 = vfmadd213sd_fma(auVar6, auVar5, auVar15);
                    auVar15._8_8_ = 0;
                    auVar15._0_8_ = *(ulonglong *)(&DAT_181130570 + (ulonglong)uVar19 * 8);
                    auVar5 = vfmadd213sd_fma(auVar5, auVar15, auVar15);
                    dVar16 = auVar5._0_8_ *
                             (double)((ulonglong)(uint)((int)(auVar18._0_4_ - uVar19) >> 6) + 0x3ff << 0x34);
                    return CONCAT44((int)((ulonglong)dVar16 >> 0x20), (float)dVar16);
                }
                auVar12._0_4_ = FUN_18105d428(fVar1, 0.0, 2);
                auVar12._4_60_ = extraout_var_02;
                uVar4 = auVar12._0_8_;
            }
            return uVar4;
        }
        if (fVar2 != INFINITY)
        {
            if (fVar2 == -INFINITY)
            {
                return 0;
            }
            auVar14._0_4_ = FUN_18105d428(fVar2, (float)((uint)fVar2 | 0x400000), 1);
            auVar14._4_60_ = extraout_var_04;
            uVar4 = auVar14._0_8_;
        }
    }
    return uVar4;
}
