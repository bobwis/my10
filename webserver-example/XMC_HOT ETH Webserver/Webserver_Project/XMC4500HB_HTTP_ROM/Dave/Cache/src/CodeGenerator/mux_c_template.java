package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class mux_c_template
{
  protected static String nl;
  public static synchronized mux_c_template create(String lineSeparator)
  {
    nl = lineSeparator;
    mux_c_template result = new mux_c_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = NL + "/*******************************************************************************" + NL + " Copyright (c) 2011, Infineon Technologies AG                                 **" + NL + " All rights reserved.                                                         **" + NL + "                                                                              **" + NL + " Redistribution and use in source and binary forms, with or without           **" + NL + " modification,are permitted provided that the following conditions are met:   **" + NL + "                                                                              **" + NL + " *Redistributions of source code must retain the above copyright notice,      **" + NL + " this list of conditions and the following disclaimer.                        **" + NL + " *Redistributions in binary form must reproduce the above copyright notice,   **" + NL + " this list of conditions and the following disclaimer in the documentation    **" + NL + " and/or other materials provided with the distribution.                       **" + NL + " *Neither the name of the copyright holders nor the names of its contributors **" + NL + " may be used to endorse or promote products derived from this software without**" + NL + " specific prior written permission.                                           **" + NL + "                                                                              **" + NL + " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"  **" + NL + " AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **" + NL + " IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **" + NL + " ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **" + NL + " LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **" + NL + " CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **" + NL + " SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **" + NL + " INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **" + NL + " CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **" + NL + " ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **" + NL + " POSSIBILITY OF SUCH DAMAGE.                                                  **" + NL + "                                                                              **" + NL + " To improve the quality of the software, users are encouraged to share        **" + NL + " modifications, enhancements or bug fixes with Infineon Technologies AG       **" + NL + " dave@infineon.com).                                                          **" + NL + "                                                                              **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon <Microcontroller name, step>                           **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : February 12, 2013                                       **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/**" + NL + " * @file  MULTIPLEXER.c" + NL + " *" + NL + " * @brief This file contains implementation of DAVE Support function which " + NL + " * uses to configure multiplexer register values." + NL + " *" + NL + " */" + NL + "" + NL + "/*******************************************************************************" + NL + "**                      Include Files                                         **" + NL + "*******************************************************************************/" + NL + "#include \"../../inc/DAVESupport/DAVE3.h\"" + NL + "" + NL + "/*******************************************************************************" + NL + "**                 Function declarations                                     **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "** Syntax           : void DAVE_MUX_Init(void)                                **" + NL + "**                                                                            **" + NL + "** Reentrancy       : None                                                    **" + NL + "**                                                                            **" + NL + "** Parameters (in)  : void                                                    **" + NL + "**                                                                            **" + NL + "** Parameters (out) : none                                                    **" + NL + "**                                                                            **" + NL + "** Return value     : none                                                    **" + NL + "**                                                                            **" + NL + "** Description      : This is the Mux configuration                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "           " + NL + "void DAVE_MUX_Init(void)" + NL + "{  ";
  protected final String TEXT_2 = NL + "        //********* Capture/Compare Unit 4 (CAPCOM4) CONFIGURATIONS ************************* ";
  protected final String TEXT_3 = NL + "               " + NL + "    // GCTRL: Global Control Register." + NL + "    WR_REG(CCU4";
  protected final String TEXT_4 = "->GCTRL, CCU4_GCTRL_PCIS_Msk, CCU4_GCTRL_PCIS_Pos, ";
  protected final String TEXT_5 = " );";
  protected final String TEXT_6 = NL + "                       " + NL + "    // Configuring CCU4";
  protected final String TEXT_7 = " CC4";
  protected final String TEXT_8 = "INS - Input Selector Configuration";
  protected final String TEXT_9 = NL;
  protected final String TEXT_10 = NL + "    ";
  protected final String TEXT_11 = "                   ";
  protected final String TEXT_12 = NL;
  protected final String TEXT_13 = NL + "    ";
  protected final String TEXT_14 = "                   ";
  protected final String TEXT_15 = NL;
  protected final String TEXT_16 = NL + "    ";
  protected final String TEXT_17 = "                   ";
  protected final String TEXT_18 = NL + "                       " + NL + "    // Configuring CCU4";
  protected final String TEXT_19 = "_CC4";
  protected final String TEXT_20 = "SRS  =  Service Request Selector";
  protected final String TEXT_21 = NL;
  protected final String TEXT_22 = NL + "    ";
  protected final String TEXT_23 = "    ";
  protected final String TEXT_24 = NL;
  protected final String TEXT_25 = NL + "    ";
  protected final String TEXT_26 = "    ";
  protected final String TEXT_27 = NL;
  protected final String TEXT_28 = NL + "    ";
  protected final String TEXT_29 = "    ";
  protected final String TEXT_30 = NL;
  protected final String TEXT_31 = NL + "    ";
  protected final String TEXT_32 = "    ";
  protected final String TEXT_33 = NL;
  protected final String TEXT_34 = NL + "    ";
  protected final String TEXT_35 = "    ";
  protected final String TEXT_36 = NL + "        //********* Capture/Compare Unit 8 (CAPCOM8) CONFIGURATIONS *************************";
  protected final String TEXT_37 = NL + "               " + NL + "    // GCTRL: Global Control Register." + NL + "    WR_REG(CCU8";
  protected final String TEXT_38 = "->GCTRL, CCU8_GCTRL_PCIS_Msk, CCU8_GCTRL_PCIS_Pos, ";
  protected final String TEXT_39 = " );";
  protected final String TEXT_40 = NL + "                      " + NL + "            // Configuring CCU8";
  protected final String TEXT_41 = " CC8";
  protected final String TEXT_42 = "INS - Input Selector Configuration";
  protected final String TEXT_43 = NL;
  protected final String TEXT_44 = NL + "    ";
  protected final String TEXT_45 = "                   ";
  protected final String TEXT_46 = NL;
  protected final String TEXT_47 = NL + "    ";
  protected final String TEXT_48 = "                   ";
  protected final String TEXT_49 = NL;
  protected final String TEXT_50 = NL + "    ";
  protected final String TEXT_51 = "                   ";
  protected final String TEXT_52 = NL + "                       " + NL + "            // Configuring CCU8";
  protected final String TEXT_53 = "_CC8";
  protected final String TEXT_54 = "SRS  =  Service Request Selector";
  protected final String TEXT_55 = NL;
  protected final String TEXT_56 = NL + "            ";
  protected final String TEXT_57 = "    ";
  protected final String TEXT_58 = NL;
  protected final String TEXT_59 = NL + "            ";
  protected final String TEXT_60 = "    ";
  protected final String TEXT_61 = NL;
  protected final String TEXT_62 = NL + "            ";
  protected final String TEXT_63 = "    ";
  protected final String TEXT_64 = NL;
  protected final String TEXT_65 = NL + "            ";
  protected final String TEXT_66 = "    ";
  protected final String TEXT_67 = NL;
  protected final String TEXT_68 = NL + "            ";
  protected final String TEXT_69 = "    ";
  protected final String TEXT_70 = NL;
  protected final String TEXT_71 = NL + "            ";
  protected final String TEXT_72 = "    ";
  protected final String TEXT_73 = NL + "    //********* Ethernet MAC CONFIGURATIONS *************************";
  protected final String TEXT_74 = NL + "                     " + NL + "    // Configuring ETH0_CON  =  Ethernet x Port Control Register";
  protected final String TEXT_75 = NL;
  protected final String TEXT_76 = NL + "    ";
  protected final String TEXT_77 = "                   ";
  protected final String TEXT_78 = NL;
  protected final String TEXT_79 = NL + "    ";
  protected final String TEXT_80 = "                   ";
  protected final String TEXT_81 = NL;
  protected final String TEXT_82 = NL + "    ";
  protected final String TEXT_83 = "                   ";
  protected final String TEXT_84 = NL;
  protected final String TEXT_85 = NL + "    ";
  protected final String TEXT_86 = "                   ";
  protected final String TEXT_87 = NL;
  protected final String TEXT_88 = NL + "    ";
  protected final String TEXT_89 = "                   ";
  protected final String TEXT_90 = NL;
  protected final String TEXT_91 = NL + "    ";
  protected final String TEXT_92 = "                   ";
  protected final String TEXT_93 = NL;
  protected final String TEXT_94 = NL + "    ";
  protected final String TEXT_95 = "                   ";
  protected final String TEXT_96 = NL;
  protected final String TEXT_97 = NL + "    ";
  protected final String TEXT_98 = "                   ";
  protected final String TEXT_99 = NL;
  protected final String TEXT_100 = NL + "    ";
  protected final String TEXT_101 = "                   ";
  protected final String TEXT_102 = NL;
  protected final String TEXT_103 = NL + "    ";
  protected final String TEXT_104 = "                   ";
  protected final String TEXT_105 = NL;
  protected final String TEXT_106 = NL + "    ";
  protected final String TEXT_107 = "                   ";
  protected final String TEXT_108 = NL;
  protected final String TEXT_109 = NL + "    ";
  protected final String TEXT_110 = "                   ";
  protected final String TEXT_111 = NL + "               ";
  protected final String TEXT_112 = NL + "                          " + NL + "    // Demodulator Input Configuration Register ";
  protected final String TEXT_113 = "        " + NL;
  protected final String TEXT_114 = NL + "    ";
  protected final String TEXT_115 = NL + NL + "\t";
  protected final String TEXT_116 = "  ";
  protected final String TEXT_117 = NL + "        " + NL + "\t";
  protected final String TEXT_118 = "                   ";
  protected final String TEXT_119 = NL + "               " + NL + "    // Rectification Configuration Register ";
  protected final String TEXT_120 = "              " + NL + "    WR_REG(DSD_CH";
  protected final String TEXT_121 = "->RECTCFG, DSD_CH_RECTCFG_SSRC_Msk, DSD_CH_RECTCFG_SSRC_Pos, ";
  protected final String TEXT_122 = ");                ";
  protected final String TEXT_123 = NL + "/*" + NL + " * CAN peripheral configuration:" + NL + " */         ";
  protected final String TEXT_124 = " ";
  protected final String TEXT_125 = "            ";
  protected final String TEXT_126 = NL + "    //Node";
  protected final String TEXT_127 = " configuration:    ";
  protected final String TEXT_128 = NL + "    WR_REG(CAN_NODE";
  protected final String TEXT_129 = "->NCR, CAN_NODE_NCR_CCE_Msk, CAN_NODE_NCR_CCE_Pos, 1); // Configuration Change Enable = 1" + NL + "    WR_REG(CAN_NODE";
  protected final String TEXT_130 = "->NPCR, CAN_NODE_NPCR_RXSEL_Msk, CAN_NODE_NPCR_RXSEL_Pos, RXD_SIGNAL";
  protected final String TEXT_131 = ");" + NL + "    ";
  protected final String TEXT_132 = " ";
  protected final String TEXT_133 = "            ";
  protected final String TEXT_134 = NL + "    //Node";
  protected final String TEXT_135 = " configuration:" + NL + "    ";
  protected final String TEXT_136 = NL + "    WR_REG(CAN_NODE";
  protected final String TEXT_137 = "->NIPR, CAN_NODE_NIPR_TRINP_Msk, CAN_NODE_NIPR_TRINP_Pos, SRN";
  protected final String TEXT_138 = ");" + NL + "    ";
  protected final String TEXT_139 = " ";
  protected final String TEXT_140 = "            ";
  protected final String TEXT_141 = NL + "    //Node";
  protected final String TEXT_142 = " configuration:" + NL + "    ";
  protected final String TEXT_143 = NL + "    WR_REG(CAN_NODE";
  protected final String TEXT_144 = "->NIPR, CAN_NODE_NIPR_LECINP_Msk, CAN_NODE_NIPR_LECINP_Pos, SRN";
  protected final String TEXT_145 = ");" + NL + "    ";
  protected final String TEXT_146 = " ";
  protected final String TEXT_147 = "            ";
  protected final String TEXT_148 = NL + "    //Node";
  protected final String TEXT_149 = " configuration:" + NL + "    ";
  protected final String TEXT_150 = NL + "    WR_REG(CAN_NODE";
  protected final String TEXT_151 = "->NIPR, CAN_NODE_NIPR_ALINP_Msk, CAN_NODE_NIPR_ALINP_Pos, SRN";
  protected final String TEXT_152 = ");" + NL + "    ";
  protected final String TEXT_153 = " ";
  protected final String TEXT_154 = "            ";
  protected final String TEXT_155 = NL + "    //Node";
  protected final String TEXT_156 = " configuration:" + NL + "    ";
  protected final String TEXT_157 = NL + "    WR_REG(CAN_NODE";
  protected final String TEXT_158 = "->NIPR, CAN_NODE_NIPR_CFCINP_Msk, CAN_NODE_NIPR_CFCINP_Pos, SRN";
  protected final String TEXT_159 = ");" + NL + "    ";
  protected final String TEXT_160 = " ";
  protected final String TEXT_161 = "            ";
  protected final String TEXT_162 = NL + "    //Message objest ";
  protected final String TEXT_163 = " configuration:" + NL + "    ";
  protected final String TEXT_164 = NL + "    WR_REG(CAN_MO";
  protected final String TEXT_165 = "->MOIPR, CAN_MO_MOIPR_TXINP_Msk, CAN_MO_MOIPR_TXINP_Pos, SRN";
  protected final String TEXT_166 = ");    ";
  protected final String TEXT_167 = " ";
  protected final String TEXT_168 = "            ";
  protected final String TEXT_169 = NL + "    //Message objest ";
  protected final String TEXT_170 = " configuration:" + NL + "    ";
  protected final String TEXT_171 = NL + "    WR_REG(CAN_MO";
  protected final String TEXT_172 = "->MOIPR, CAN_MO_MOIPR_RXINP_Msk, CAN_MO_MOIPR_RXINP_Pos, SRN";
  protected final String TEXT_173 = ");" + NL + "    ";
  protected final String TEXT_174 = NL + "/*" + NL + " * POSIF0 peripheral configuration:" + NL + " */         ";
  protected final String TEXT_175 = " ";
  protected final String TEXT_176 = "            ";
  protected final String TEXT_177 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_178 = NL + "    WR_REG(POSIF0->PCONF, POSIF_PCONF_INSEL0_Msk, POSIF_PCONF_INSEL0_Pos, INSIGNAL";
  protected final String TEXT_179 = ");" + NL + "    ";
  protected final String TEXT_180 = " ";
  protected final String TEXT_181 = "            ";
  protected final String TEXT_182 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_183 = NL + "    WR_REG(POSIF0->PCONF, POSIF_PCONF_INSEL1_Msk, POSIF_PCONF_INSEL1_Pos, INSIGNAL";
  protected final String TEXT_184 = ");" + NL + "    ";
  protected final String TEXT_185 = " ";
  protected final String TEXT_186 = "            ";
  protected final String TEXT_187 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_188 = NL + "    WR_REG(POSIF0->PCONF, POSIF_PCONF_INSEL2_Msk, POSIF_PCONF_INSEL2_Pos, INSIGNAL";
  protected final String TEXT_189 = ");" + NL + "    ";
  protected final String TEXT_190 = " ";
  protected final String TEXT_191 = "            ";
  protected final String TEXT_192 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_193 = NL + "    WR_REG(POSIF0->PCONF, POSIF_PCONF_DSEL_Msk, POSIF_PCONF_DSEL_Pos, INSIGNAL";
  protected final String TEXT_194 = ");" + NL + "    ";
  protected final String TEXT_195 = " ";
  protected final String TEXT_196 = "            ";
  protected final String TEXT_197 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_198 = NL + "    WR_REG(POSIF0->PCONF, POSIF_PCONF_EWIS_Msk, POSIF_PCONF_EWIS_Pos, INSIGNAL";
  protected final String TEXT_199 = ");" + NL + "    ";
  protected final String TEXT_200 = " ";
  protected final String TEXT_201 = "            ";
  protected final String TEXT_202 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_203 = NL + "    WR_REG(POSIF0->PCONF, POSIF_PCONF_MSETS_Msk, POSIF_PCONF_MSETS_Pos, INSIGNAL";
  protected final String TEXT_204 = ");" + NL + "    ";
  protected final String TEXT_205 = " ";
  protected final String TEXT_206 = "            ";
  protected final String TEXT_207 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_208 = NL + "    WR_REG(POSIF0->PCONF, POSIF_PCONF_MSYNS_Msk, POSIF_PCONF_MSYNS_Pos, INSIGNAL";
  protected final String TEXT_209 = ");" + NL + "    ";
  protected final String TEXT_210 = " ";
  protected final String TEXT_211 = "            ";
  protected final String TEXT_212 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_213 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_ECHE_Msk, POSIF_PFLGE_ECHE_Pos, SET_";
  protected final String TEXT_214 = ");" + NL + "    ";
  protected final String TEXT_215 = " ";
  protected final String TEXT_216 = "            ";
  protected final String TEXT_217 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_218 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_CHESEL_Msk, POSIF_PFLGE_CHESEL_Pos, SR";
  protected final String TEXT_219 = ");" + NL + "    ";
  protected final String TEXT_220 = " ";
  protected final String TEXT_221 = "            ";
  protected final String TEXT_222 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_223 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_EWHE_Msk, POSIF_PFLGE_EWHE_Pos, SET_";
  protected final String TEXT_224 = ");" + NL + "    ";
  protected final String TEXT_225 = " ";
  protected final String TEXT_226 = "            ";
  protected final String TEXT_227 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_228 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_WHESEL_Msk, POSIF_PFLGE_WHESEL_Pos, SR";
  protected final String TEXT_229 = ");" + NL + "    ";
  protected final String TEXT_230 = " ";
  protected final String TEXT_231 = "            ";
  protected final String TEXT_232 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_233 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_EHIE_Msk, POSIF_PFLGE_EHIE_Pos, SET_";
  protected final String TEXT_234 = ");" + NL + "    ";
  protected final String TEXT_235 = " ";
  protected final String TEXT_236 = "            ";
  protected final String TEXT_237 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_238 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_HIESEL_Msk, POSIF_PFLGE_HIESEL_Pos, SR";
  protected final String TEXT_239 = ");" + NL + "    ";
  protected final String TEXT_240 = " ";
  protected final String TEXT_241 = "            ";
  protected final String TEXT_242 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_243 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_EMST_Msk, POSIF_PFLGE_EMST_Pos, SET_";
  protected final String TEXT_244 = ");" + NL + "    ";
  protected final String TEXT_245 = " ";
  protected final String TEXT_246 = "            ";
  protected final String TEXT_247 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_248 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_MSTSEL_Msk, POSIF_PFLGE_MSTSEL_Pos, SR";
  protected final String TEXT_249 = ");" + NL + "    ";
  protected final String TEXT_250 = " ";
  protected final String TEXT_251 = "            ";
  protected final String TEXT_252 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_253 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_EINDX_Msk, POSIF_PFLGE_EINDX_Pos, SET_";
  protected final String TEXT_254 = ");" + NL + "    ";
  protected final String TEXT_255 = " ";
  protected final String TEXT_256 = "            ";
  protected final String TEXT_257 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_258 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_INDSEL_Msk, POSIF_PFLGE_INDSEL_Pos, SR";
  protected final String TEXT_259 = ");" + NL + "    ";
  protected final String TEXT_260 = " ";
  protected final String TEXT_261 = "            ";
  protected final String TEXT_262 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_263 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_EERR_Msk, POSIF_PFLGE_EERR_Pos, SET_";
  protected final String TEXT_264 = ");" + NL + "    ";
  protected final String TEXT_265 = " ";
  protected final String TEXT_266 = "            ";
  protected final String TEXT_267 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_268 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_ERRSEL_Msk, POSIF_PFLGE_ERRSEL_Pos, SR";
  protected final String TEXT_269 = ");" + NL + "    ";
  protected final String TEXT_270 = " ";
  protected final String TEXT_271 = "            ";
  protected final String TEXT_272 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_273 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_ECNT_Msk, POSIF_PFLGE_ECNT_Pos, SET_";
  protected final String TEXT_274 = ");" + NL + "    ";
  protected final String TEXT_275 = " ";
  protected final String TEXT_276 = "            ";
  protected final String TEXT_277 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_278 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_CNTSEL_Msk, POSIF_PFLGE_CNTSEL_Pos, SR";
  protected final String TEXT_279 = ");" + NL + "    ";
  protected final String TEXT_280 = " ";
  protected final String TEXT_281 = "            ";
  protected final String TEXT_282 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_283 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_EDIR_Msk, POSIF_PFLGE_EDIR_Pos, SET_";
  protected final String TEXT_284 = ");" + NL + "    ";
  protected final String TEXT_285 = " ";
  protected final String TEXT_286 = "            ";
  protected final String TEXT_287 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_288 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_DIRSEL_Msk, POSIF_PFLGE_DIRSEL_Pos, SR";
  protected final String TEXT_289 = ");" + NL + "    ";
  protected final String TEXT_290 = " ";
  protected final String TEXT_291 = "            ";
  protected final String TEXT_292 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_293 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_EPCLK_Msk, POSIF_PFLGE_EPCLK_Pos, SET_";
  protected final String TEXT_294 = ");" + NL + "    ";
  protected final String TEXT_295 = " ";
  protected final String TEXT_296 = "            ";
  protected final String TEXT_297 = NL + "    //POSIF0 configuration:" + NL + "    ";
  protected final String TEXT_298 = NL + "    WR_REG(POSIF0->PFLGE, POSIF_PFLGE_PCLSEL_Msk, POSIF_PFLGE_PCLSEL_Pos, SR";
  protected final String TEXT_299 = ");" + NL + "    ";
  protected final String TEXT_300 = NL + NL + "/*" + NL + " * POSIF1 peripheral configuration:" + NL + " */         ";
  protected final String TEXT_301 = " ";
  protected final String TEXT_302 = "            ";
  protected final String TEXT_303 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_304 = NL + "    WR_REG(POSIF1->PCONF, POSIF_PCONF_INSEL0_Msk, POSIF_PCONF_INSEL0_Pos, INSIGNAL";
  protected final String TEXT_305 = ");" + NL + "    ";
  protected final String TEXT_306 = " ";
  protected final String TEXT_307 = "            ";
  protected final String TEXT_308 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_309 = NL + "    WR_REG(POSIF1->PCONF, POSIF_PCONF_INSEL1_Msk, POSIF_PCONF_INSEL1_Pos, INSIGNAL";
  protected final String TEXT_310 = ");" + NL + "    ";
  protected final String TEXT_311 = " ";
  protected final String TEXT_312 = "            ";
  protected final String TEXT_313 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_314 = NL + "    WR_REG(POSIF1->PCONF, POSIF_PCONF_INSEL2_Msk, POSIF_PCONF_INSEL2_Pos, INSIGNAL";
  protected final String TEXT_315 = ");" + NL + "    ";
  protected final String TEXT_316 = " ";
  protected final String TEXT_317 = "            ";
  protected final String TEXT_318 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_319 = NL + "    WR_REG(POSIF1->PCONF, POSIF_PCONF_DSEL_Msk, POSIF_PCONF_DSEL_Pos, INSIGNAL";
  protected final String TEXT_320 = ");" + NL + "    ";
  protected final String TEXT_321 = " ";
  protected final String TEXT_322 = "            ";
  protected final String TEXT_323 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_324 = NL + "    WR_REG(POSIF1->PCONF, POSIF_PCONF_EWIS_Msk, POSIF_PCONF_EWIS_Pos, INSIGNAL";
  protected final String TEXT_325 = ");" + NL + "    ";
  protected final String TEXT_326 = " ";
  protected final String TEXT_327 = "            ";
  protected final String TEXT_328 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_329 = NL + "    WR_REG(POSIF1->PCONF, POSIF_PCONF_MSETS_Msk, POSIF_PCONF_MSETS_Pos, INSIGNAL";
  protected final String TEXT_330 = ");" + NL + "    ";
  protected final String TEXT_331 = " ";
  protected final String TEXT_332 = "            ";
  protected final String TEXT_333 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_334 = NL + "    WR_REG(POSIF1->PCONF, POSIF_PCONF_MSYNS_Msk, POSIF_PCONF_MSYNS_Pos, INSIGNAL";
  protected final String TEXT_335 = ");" + NL + "    ";
  protected final String TEXT_336 = " ";
  protected final String TEXT_337 = "            ";
  protected final String TEXT_338 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_339 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_ECHE_Msk, POSIF_PFLGE_ECHE_Pos, SET_";
  protected final String TEXT_340 = ");" + NL + "    ";
  protected final String TEXT_341 = " ";
  protected final String TEXT_342 = "            ";
  protected final String TEXT_343 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_344 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_CHESEL_Msk, POSIF_PFLGE_CHESEL_Pos, SR";
  protected final String TEXT_345 = ");" + NL + "    ";
  protected final String TEXT_346 = " ";
  protected final String TEXT_347 = "            ";
  protected final String TEXT_348 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_349 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_EWHE_Msk, POSIF_PFLGE_EWHE_Pos, SET_";
  protected final String TEXT_350 = ");" + NL + "    ";
  protected final String TEXT_351 = " ";
  protected final String TEXT_352 = "            ";
  protected final String TEXT_353 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_354 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_WHESEL_Msk, POSIF_PFLGE_WHESEL_Pos, SR";
  protected final String TEXT_355 = ");" + NL + "    ";
  protected final String TEXT_356 = " ";
  protected final String TEXT_357 = "            ";
  protected final String TEXT_358 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_359 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_EHIE_Msk, POSIF_PFLGE_EHIE_Pos, SET_";
  protected final String TEXT_360 = ");" + NL + "    ";
  protected final String TEXT_361 = " ";
  protected final String TEXT_362 = "            ";
  protected final String TEXT_363 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_364 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_HIESEL_Msk, POSIF_PFLGE_HIESEL_Pos, SR";
  protected final String TEXT_365 = ");" + NL + "    ";
  protected final String TEXT_366 = " ";
  protected final String TEXT_367 = "            ";
  protected final String TEXT_368 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_369 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_EMST_Msk, POSIF_PFLGE_EMST_Pos, SET_";
  protected final String TEXT_370 = ");" + NL + "    ";
  protected final String TEXT_371 = " ";
  protected final String TEXT_372 = "            ";
  protected final String TEXT_373 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_374 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_MSTSEL_Msk, POSIF_PFLGE_MSTSEL_Pos, SR";
  protected final String TEXT_375 = ");" + NL + "    ";
  protected final String TEXT_376 = " ";
  protected final String TEXT_377 = "            ";
  protected final String TEXT_378 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_379 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_EINDX_Msk, POSIF_PFLGE_EINDX_Pos, SET_";
  protected final String TEXT_380 = ");" + NL + "    ";
  protected final String TEXT_381 = " ";
  protected final String TEXT_382 = "            ";
  protected final String TEXT_383 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_384 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_INDSEL_Msk, POSIF_PFLGE_INDSEL_Pos, SR";
  protected final String TEXT_385 = ");" + NL + "    ";
  protected final String TEXT_386 = " ";
  protected final String TEXT_387 = "            ";
  protected final String TEXT_388 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_389 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_EERR_Msk, POSIF_PFLGE_EERR_Pos, SET_";
  protected final String TEXT_390 = ");" + NL + "    ";
  protected final String TEXT_391 = " ";
  protected final String TEXT_392 = "            ";
  protected final String TEXT_393 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_394 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_ERRSEL_Msk, POSIF_PFLGE_ERRSEL_Pos, SR";
  protected final String TEXT_395 = ");" + NL + "    ";
  protected final String TEXT_396 = " ";
  protected final String TEXT_397 = "            ";
  protected final String TEXT_398 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_399 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_ECNT_Msk, POSIF_PFLGE_ECNT_Pos, SET_";
  protected final String TEXT_400 = ");" + NL + "    ";
  protected final String TEXT_401 = " ";
  protected final String TEXT_402 = "            ";
  protected final String TEXT_403 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_404 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_CNTSEL_Msk, POSIF_PFLGE_CNTSEL_Pos, SR";
  protected final String TEXT_405 = ");" + NL + "    ";
  protected final String TEXT_406 = " ";
  protected final String TEXT_407 = "            ";
  protected final String TEXT_408 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_409 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_EDIR_Msk, POSIF_PFLGE_EDIR_Pos, SET_";
  protected final String TEXT_410 = ");" + NL + "    ";
  protected final String TEXT_411 = " ";
  protected final String TEXT_412 = "            ";
  protected final String TEXT_413 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_414 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_DIRSEL_Msk, POSIF_PFLGE_DIRSEL_Pos, SR";
  protected final String TEXT_415 = ");" + NL + "    ";
  protected final String TEXT_416 = " ";
  protected final String TEXT_417 = "            ";
  protected final String TEXT_418 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_419 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_EPCLK_Msk, POSIF_PFLGE_EPCLK_Pos, SET_";
  protected final String TEXT_420 = ");" + NL + "    ";
  protected final String TEXT_421 = " ";
  protected final String TEXT_422 = "            ";
  protected final String TEXT_423 = NL + "    //POSIF1 configuration:" + NL + "    ";
  protected final String TEXT_424 = NL + "    WR_REG(POSIF1->PFLGE, POSIF_PFLGE_PCLSEL_Msk, POSIF_PFLGE_PCLSEL_Pos, SR";
  protected final String TEXT_425 = ");" + NL + "    ";
  protected final String TEXT_426 = "    ";
  protected final String TEXT_427 = "  " + NL + "//********* MODULE USIC CONFIGURATIONS *************************\t        ";
  protected final String TEXT_428 = " \t\t\t\t\t\t" + NL + "   /*USIC ";
  protected final String TEXT_429 = " Channel ";
  protected final String TEXT_430 = " Mux Related SFR/Bitfields Configurations*/ \t\t\t\t\t\t";
  protected final String TEXT_431 = "         " + NL + " WR_REG(USIC";
  protected final String TEXT_432 = "_CH";
  protected final String TEXT_433 = "->DX0CR, USIC_CH_DX0CR_DSEL_Msk, USIC_CH_DX0CR_DSEL_Pos,";
  protected final String TEXT_434 = "); " + NL + "  ";
  protected final String TEXT_435 = "\t\t\t ";
  protected final String TEXT_436 = "                 " + NL + " WR_REG(USIC";
  protected final String TEXT_437 = "_CH";
  protected final String TEXT_438 = "->DX1CR, USIC_CH_DX1CR_DSEL_Msk, USIC_CH_DX1CR_DSEL_Pos,";
  protected final String TEXT_439 = ");  " + NL + " ";
  protected final String TEXT_440 = " \t\t\t\t\t ";
  protected final String TEXT_441 = "   " + NL + " WR_REG(USIC";
  protected final String TEXT_442 = "_CH";
  protected final String TEXT_443 = "->DX2CR, USIC_CH_DX2CR_DSEL_Msk, USIC_CH_DX2CR_DSEL_Pos,";
  protected final String TEXT_444 = ");  " + NL + " ";
  protected final String TEXT_445 = "\t\t\t\t";
  protected final String TEXT_446 = "   " + NL + " WR_REG(USIC";
  protected final String TEXT_447 = "_CH";
  protected final String TEXT_448 = "->DX3CR, USIC_CH_DX3CR_DSEL_Msk, USIC_CH_DX3CR_DSEL_Pos,";
  protected final String TEXT_449 = ");" + NL + "   ";
  protected final String TEXT_450 = " \t\t\t\t";
  protected final String TEXT_451 = "   " + NL + " WR_REG(USIC";
  protected final String TEXT_452 = "_CH";
  protected final String TEXT_453 = "->DX4CR, USIC_CH_DX4CR_DSEL_Msk, USIC_CH_DX4CR_DSEL_Pos,";
  protected final String TEXT_454 = "); " + NL + "  ";
  protected final String TEXT_455 = " \t\t      ";
  protected final String TEXT_456 = "   " + NL + " WR_REG(USIC";
  protected final String TEXT_457 = "_CH";
  protected final String TEXT_458 = "->DX5CR, USIC_CH_DX5CR_DSEL_Msk, USIC_CH_DX5CR_DSEL_Pos,";
  protected final String TEXT_459 = ");  " + NL + " ";
  protected final String TEXT_460 = " \t\t\t\t             ";
  protected final String TEXT_461 = "   " + NL + " //Hardware port control is enabled.                 " + NL + " WR_REG(USIC";
  protected final String TEXT_462 = "_CH";
  protected final String TEXT_463 = "->CCR, USIC_CH_CCR_HPCEN_Msk, USIC_CH_CCR_HPCEN_Pos,";
  protected final String TEXT_464 = ");" + NL + "   ";
  protected final String TEXT_465 = " \t\t\t\t ";
  protected final String TEXT_466 = "   " + NL + " //Transmit shift event event is enabled.                " + NL + " WR_REG(USIC";
  protected final String TEXT_467 = "_CH";
  protected final String TEXT_468 = "->CCR, USIC_CH_CCR_TSIEN_Msk, USIC_CH_CCR_TSIEN_Pos,";
  protected final String TEXT_469 = ");  " + NL + " ";
  protected final String TEXT_470 = " \t\t\t\t\t   ";
  protected final String TEXT_471 = "   " + NL + " //Transmit buffer event event is enabled.                       " + NL + " WR_REG(USIC";
  protected final String TEXT_472 = "_CH";
  protected final String TEXT_473 = "->CCR, USIC_CH_CCR_TBIEN_Msk, USIC_CH_CCR_TBIEN_Pos,";
  protected final String TEXT_474 = ");  " + NL + " ";
  protected final String TEXT_475 = " \t\t\t\t\t";
  protected final String TEXT_476 = "   " + NL + " //Receive start event event is enabled.                    " + NL + " WR_REG(USIC";
  protected final String TEXT_477 = "_CH";
  protected final String TEXT_478 = "->CCR, USIC_CH_CCR_RSIEN_Msk, USIC_CH_CCR_RSIEN_Pos,";
  protected final String TEXT_479 = "); " + NL + "  ";
  protected final String TEXT_480 = " \t\t\t\t\t   ";
  protected final String TEXT_481 = "   " + NL + " //Receive event event is enabled.                " + NL + " WR_REG(USIC";
  protected final String TEXT_482 = "_CH";
  protected final String TEXT_483 = "->CCR, USIC_CH_CCR_RIEN_Msk, USIC_CH_CCR_RIEN_Pos,";
  protected final String TEXT_484 = "); " + NL + "  ";
  protected final String TEXT_485 = "\t\t\t\t ";
  protected final String TEXT_486 = "   " + NL + " //Alternative receive event event is enabled.              " + NL + " WR_REG(USIC";
  protected final String TEXT_487 = "_CH";
  protected final String TEXT_488 = "->CCR, USIC_CH_CCR_AIEN_Msk, USIC_CH_CCR_AIEN_Pos,";
  protected final String TEXT_489 = ");  " + NL + " ";
  protected final String TEXT_490 = " \t\t\t\t\t";
  protected final String TEXT_491 = "   " + NL + " //Data lost event event is enabled.                 " + NL + " WR_REG(USIC";
  protected final String TEXT_492 = "_CH";
  protected final String TEXT_493 = "->CCR, USIC_CH_CCR_DLIEN_Msk, USIC_CH_CCR_DLIEN_Pos,";
  protected final String TEXT_494 = "); " + NL + "  ";
  protected final String TEXT_495 = " \t\t\t\t ";
  protected final String TEXT_496 = "   " + NL + " //Baud rate generator event is enabled.                " + NL + " WR_REG(USIC";
  protected final String TEXT_497 = "_CH";
  protected final String TEXT_498 = "->CCR, USIC_CH_CCR_BRGIEN_Msk, USIC_CH_CCR_BRGIEN_Pos,";
  protected final String TEXT_499 = ");  " + NL + " ";
  protected final String TEXT_500 = "\t\t\t\t      ";
  protected final String TEXT_501 = "   " + NL + " //Standard transmit buffer event is enabled.                 " + NL + " WR_REG(USIC";
  protected final String TEXT_502 = "_CH";
  protected final String TEXT_503 = "->TBCTR, USIC_CH_TBCTR_STBIEN_Msk, USIC_CH_TBCTR_STBIEN_Pos,";
  protected final String TEXT_504 = ");" + NL + "   ";
  protected final String TEXT_505 = " \t\t\t\t ";
  protected final String TEXT_506 = "   " + NL + " //Transmit buffer error event is enabled.                   " + NL + " WR_REG(USIC";
  protected final String TEXT_507 = "_CH";
  protected final String TEXT_508 = "->TBCTR, USIC_CH_TBCTR_TBERIEN_Msk, USIC_CH_TBCTR_TBERIEN_Pos,";
  protected final String TEXT_509 = ");  " + NL + " ";
  protected final String TEXT_510 = " \t\t\t\t\t";
  protected final String TEXT_511 = "    " + NL + " //Standard receive buffer event is enabled.                 " + NL + " WR_REG(USIC";
  protected final String TEXT_512 = "_CH";
  protected final String TEXT_513 = "->RBCTR, USIC_CH_RBCTR_SRBIEN_Msk, USIC_CH_RBCTR_SRBIEN_Pos,";
  protected final String TEXT_514 = ");  " + NL + " ";
  protected final String TEXT_515 = "\t\t\t\t\t ";
  protected final String TEXT_516 = "   " + NL + " //Receive buffer error event is enabled.                 " + NL + " WR_REG(USIC";
  protected final String TEXT_517 = "_CH";
  protected final String TEXT_518 = "->RBCTR, USIC_CH_RBCTR_RBERIEN_Msk, USIC_CH_RBCTR_RBERIEN_Pos,";
  protected final String TEXT_519 = "); " + NL + "  ";
  protected final String TEXT_520 = "\t\t\t\t";
  protected final String TEXT_521 = "   " + NL + " //Alternative receive buffer event is enabled.           " + NL + " WR_REG(USIC";
  protected final String TEXT_522 = "_CH";
  protected final String TEXT_523 = "->RBCTR, USIC_CH_RBCTR_ARBIEN_Msk, USIC_CH_RBCTR_ARBIEN_Pos,";
  protected final String TEXT_524 = "); " + NL + "  ";
  protected final String TEXT_525 = "\t\t\t\t\t";
  protected final String TEXT_526 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_527 = " is selected for Transmit shift event                " + NL + " WR_REG(USIC";
  protected final String TEXT_528 = "_CH";
  protected final String TEXT_529 = "->INPR, USIC_CH_INPR_TSINP_Msk, USIC_CH_INPR_TSINP_Pos,";
  protected final String TEXT_530 = ");  " + NL + " ";
  protected final String TEXT_531 = " \t\t\t\t\t ";
  protected final String TEXT_532 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_533 = " is selected for Transmit buffer event                 " + NL + " WR_REG(USIC";
  protected final String TEXT_534 = "_CH";
  protected final String TEXT_535 = "->INPR, USIC_CH_INPR_TBINP_Msk, USIC_CH_INPR_TBINP_Pos,";
  protected final String TEXT_536 = ");  " + NL + " ";
  protected final String TEXT_537 = "\t\t\t\t\t ";
  protected final String TEXT_538 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_539 = " is selected for Receive event               " + NL + " WR_REG(USIC";
  protected final String TEXT_540 = "_CH";
  protected final String TEXT_541 = "->INPR, USIC_CH_INPR_RINP_Msk, USIC_CH_INPR_RINP_Pos,";
  protected final String TEXT_542 = ");  " + NL + " ";
  protected final String TEXT_543 = " \t\t\t\t";
  protected final String TEXT_544 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_545 = " is selected for Alternative receive event              " + NL + " WR_REG(USIC";
  protected final String TEXT_546 = "_CH";
  protected final String TEXT_547 = "->INPR, USIC_CH_INPR_AINP_Msk, USIC_CH_INPR_AINP_Pos,";
  protected final String TEXT_548 = ");  " + NL + " ";
  protected final String TEXT_549 = "\t\t\t\t\t      ";
  protected final String TEXT_550 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_551 = " is selected for Protocol specific event             " + NL + " WR_REG(USIC";
  protected final String TEXT_552 = "_CH";
  protected final String TEXT_553 = "->INPR, USIC_CH_INPR_PINP_Msk, USIC_CH_INPR_PINP_Pos,";
  protected final String TEXT_554 = ");  " + NL + " ";
  protected final String TEXT_555 = "\t\t\t\t\t             ";
  protected final String TEXT_556 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_557 = " is selected for Standard transmit buffer event                " + NL + " WR_REG(USIC";
  protected final String TEXT_558 = "_CH";
  protected final String TEXT_559 = "->TBCTR, USIC_CH_TBCTR_STBINP_Msk, USIC_CH_TBCTR_STBINP_Pos,";
  protected final String TEXT_560 = ");" + NL + "   ";
  protected final String TEXT_561 = " \t\t\t\t\t";
  protected final String TEXT_562 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_563 = " is selected for Alternative transmit buffer event                " + NL + " WR_REG(USIC";
  protected final String TEXT_564 = "_CH";
  protected final String TEXT_565 = "->TBCTR, USIC_CH_TBCTR_ATBINP_Msk, USIC_CH_TBCTR_ATBINP_Pos,";
  protected final String TEXT_566 = "); " + NL + "  ";
  protected final String TEXT_567 = "  \t\t\t\t\t\t    ";
  protected final String TEXT_568 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_569 = " is selected for Standard receive buffer event                 " + NL + " WR_REG(USIC";
  protected final String TEXT_570 = "_CH";
  protected final String TEXT_571 = "->RBCTR, USIC_CH_RBCTR_SRBINP_Msk, USIC_CH_RBCTR_SRBINP_Pos,";
  protected final String TEXT_572 = ");  " + NL + " ";
  protected final String TEXT_573 = "\t\t\t\t\t     ";
  protected final String TEXT_574 = "   " + NL + " //Interrupt node ";
  protected final String TEXT_575 = " is selected for Alternative receive buffer event            " + NL + " WR_REG(USIC";
  protected final String TEXT_576 = "_CH";
  protected final String TEXT_577 = "->RBCTR, USIC_CH_RBCTR_ARBINP_Msk, USIC_CH_RBCTR_ARBINP_Pos,";
  protected final String TEXT_578 = ");  " + NL + " ";
  protected final String TEXT_579 = " " + NL;
  protected final String TEXT_580 = " ";
  protected final String TEXT_581 = "    ";
  protected final String TEXT_582 = "   ";
  protected final String TEXT_583 = " ";
  protected final String TEXT_584 = "    ";
  protected final String TEXT_585 = " ";
  protected final String TEXT_586 = "  ";
  protected final String TEXT_587 = " " + NL + "   // Data Pointer & Buffer Size for Transmitter Buffer Control  " + NL + " WR_REG(USIC";
  protected final String TEXT_588 = "_CH";
  protected final String TEXT_589 = "->TBCTR, USIC_CH_TBCTR_DPTRSIZE_Msk, USIC_CH_TBCTR_DPTRSIZE_Pos,0x0";
  protected final String TEXT_590 = ");\t\t/*    DPTR = ";
  protected final String TEXT_591 = ",  SIZE = ";
  protected final String TEXT_592 = " */ " + NL;
  protected final String TEXT_593 = " ";
  protected final String TEXT_594 = " ";
  protected final String TEXT_595 = " ";
  protected final String TEXT_596 = " ";
  protected final String TEXT_597 = "  ";
  protected final String TEXT_598 = " ";
  protected final String TEXT_599 = " ";
  protected final String TEXT_600 = "  ";
  protected final String TEXT_601 = " " + NL + "  // Data Pointer & Buffer Size for Receiver Buffer Control  " + NL + " WR_REG(USIC";
  protected final String TEXT_602 = "_CH";
  protected final String TEXT_603 = "->RBCTR, USIC_CH_RBCTR_DPTRSIZE_Msk, USIC_CH_RBCTR_DPTRSIZE_Pos,0x0";
  protected final String TEXT_604 = ");\t\t/*    DPTR = ";
  protected final String TEXT_605 = ",  SIZE = ";
  protected final String TEXT_606 = " */ " + NL;
  protected final String TEXT_607 = "  ";
  protected final String TEXT_608 = " \t        \t\t\t\t\t";
  protected final String TEXT_609 = "       ";
  protected final String TEXT_610 = "\t    " + NL + "  //********* MODULE DLR CONFIGURATIONS *************************\t     ";
  protected final String TEXT_611 = " ";
  protected final String TEXT_612 = "   ";
  protected final String TEXT_613 = "         ";
  protected final String TEXT_614 = " ";
  protected final String TEXT_615 = "    ";
  protected final String TEXT_616 = "      \t\t\t\t" + NL + "  /*DLR Line ";
  protected final String TEXT_617 = " Mux Related SFR/Bitfields Configurations*/     \t\t\t\t";
  protected final String TEXT_618 = "  " + NL + " WR_REG(DLR->SRSEL";
  protected final String TEXT_619 = ", DLR_SRSEL";
  protected final String TEXT_620 = "_RS";
  protected final String TEXT_621 = "_Msk, DLR_SRSEL";
  protected final String TEXT_622 = "_RS";
  protected final String TEXT_623 = "_Pos,";
  protected final String TEXT_624 = "); " + NL;
  protected final String TEXT_625 = "  ";
  protected final String TEXT_626 = " \t         ";
  protected final String TEXT_627 = " \t         ";
  protected final String TEXT_628 = NL + "    ";
  protected final String TEXT_629 = "           ";
  protected final String TEXT_630 = "  \t          ";
  protected final String TEXT_631 = " ";
  protected final String TEXT_632 = " " + NL + "  //********* MODULE DMA";
  protected final String TEXT_633 = " CONFIGURATIONS ************************* \t\t\t\t\t";
  protected final String TEXT_634 = "\t\t\t\t\t";
  protected final String TEXT_635 = "   ";
  protected final String TEXT_636 = " ";
  protected final String TEXT_637 = " ";
  protected final String TEXT_638 = " ";
  protected final String TEXT_639 = " ";
  protected final String TEXT_640 = " \t\t\t\t\t       ";
  protected final String TEXT_641 = "   ";
  protected final String TEXT_642 = " ";
  protected final String TEXT_643 = "  ";
  protected final String TEXT_644 = " " + NL + "  /*DMA ";
  protected final String TEXT_645 = " Channel ";
  protected final String TEXT_646 = " Mux Related SFR/Bitfields Configurations*/" + NL;
  protected final String TEXT_647 = " " + NL + "\t";
  protected final String TEXT_648 = "            " + NL + "  WR_REG(GPDMA";
  protected final String TEXT_649 = "_CH";
  protected final String TEXT_650 = "->CFGL, GPDMA";
  protected final String TEXT_651 = "_CH_CFGL_HS_SEL_SRC_Msk, GPDMA";
  protected final String TEXT_652 = "_CH_CFGL_HS_SEL_SRC_Pos,";
  protected final String TEXT_653 = "); " + NL;
  protected final String TEXT_654 = " ";
  protected final String TEXT_655 = " ";
  protected final String TEXT_656 = " " + NL + "  WR_REG(GPDMA";
  protected final String TEXT_657 = "_CH";
  protected final String TEXT_658 = "->CFGL, GPDMA";
  protected final String TEXT_659 = "_CH_CFGL_HS_SEL_DST_Msk, GPDMA";
  protected final String TEXT_660 = "_CH_CFGL_HS_SEL_DST_Pos,";
  protected final String TEXT_661 = ");" + NL;
  protected final String TEXT_662 = " ";
  protected final String TEXT_663 = "      " + NL + "  WR_REG(GPDMA";
  protected final String TEXT_664 = "_CH";
  protected final String TEXT_665 = "->CFGH, GPDMA";
  protected final String TEXT_666 = "_CH_CFGH_SRC_PER_Msk, GPDMA";
  protected final String TEXT_667 = "_CH_CFGH_SRC_PER_Pos,";
  protected final String TEXT_668 = ");" + NL;
  protected final String TEXT_669 = " ";
  protected final String TEXT_670 = "     " + NL + "  WR_REG(GPDMA";
  protected final String TEXT_671 = "_CH";
  protected final String TEXT_672 = "->CFGH, GPDMA";
  protected final String TEXT_673 = "_CH_CFGH_DEST_PER_Msk, GPDMA";
  protected final String TEXT_674 = "_CH_CFGH_DEST_PER_Pos,";
  protected final String TEXT_675 = ");" + NL;
  protected final String TEXT_676 = " ";
  protected final String TEXT_677 = "  \t\t\t\t  \t" + NL + "\t     ";
  protected final String TEXT_678 = "    ";
  protected final String TEXT_679 = "               ";
  protected final String TEXT_680 = NL + "                  /*VADC GROUP";
  protected final String TEXT_681 = " Mux Related SFR/Bitfields Configurations*/  ";
  protected final String TEXT_682 = "\t\t\t\t\t\t      ";
  protected final String TEXT_683 = " ";
  protected final String TEXT_684 = "                        ";
  protected final String TEXT_685 = "        " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_686 = "->QCTRL0, VADC_G_QCTRL0_XTWC_XTSEL_Msk, VADC_G_QCTRL0_XTSEL_Pos, \\" + NL + "     (((((VADC_G";
  protected final String TEXT_687 = "->QCTRL0) & VADC_G_QCTRL0_XTMODE_Msk) | VADC_G_QCTRL0_XTWC_Msk) >> VADC_G_QCTRL0_XTSEL_Pos) | ";
  protected final String TEXT_688 = "));" + NL + "   ";
  protected final String TEXT_689 = "                    ";
  protected final String TEXT_690 = "\t\t\t\t\t\t      ";
  protected final String TEXT_691 = " ";
  protected final String TEXT_692 = "  ";
  protected final String TEXT_693 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_694 = "->ASCTRL, VADC_G_ASCTRL_XTWC_XTSEL_Msk, VADC_G_ASCTRL_XTSEL_Pos, \\" + NL + "   (((((VADC_G";
  protected final String TEXT_695 = "->ASCTRL) & VADC_G_ASCTRL_XTMODE_Msk) | VADC_G_ASCTRL_XTWC_Msk) >> VADC_G_ASCTRL_XTSEL_Pos) | ";
  protected final String TEXT_696 = "));" + NL + "  ";
  protected final String TEXT_697 = "\t\t\t\t\t\t      ";
  protected final String TEXT_698 = " ";
  protected final String TEXT_699 = "  ";
  protected final String TEXT_700 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_701 = "->QCTRL0, VADC_G_QCTRL0_GTWC_GTSEL_Msk, VADC_G_QCTRL0_GTSEL_Pos, \\" + NL + "   (((VADC_G_QCTRL0_GTWC_Msk) >> VADC_G_QCTRL0_GTSEL_Pos) | ";
  protected final String TEXT_702 = ")); " + NL + "   ";
  protected final String TEXT_703 = "                ";
  protected final String TEXT_704 = "\t\t\t\t\t\t      ";
  protected final String TEXT_705 = " ";
  protected final String TEXT_706 = "  ";
  protected final String TEXT_707 = "   " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_708 = "->ASCTRL, VADC_G_ASCTRL_GTWC_GTSEL_Msk, VADC_G_ASCTRL_GTSEL_Pos, \\" + NL + "   (((VADC_G_ASCTRL_GTWC_Msk) >> VADC_G_ASCTRL_GTSEL_Pos) | ";
  protected final String TEXT_709 = "));  " + NL + "  ";
  protected final String TEXT_710 = "                 ";
  protected final String TEXT_711 = "\t\t\t\t\t\t      ";
  protected final String TEXT_712 = " ";
  protected final String TEXT_713 = "  ";
  protected final String TEXT_714 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_715 = "->SEVNP, VADC_G_SEVNP_SEV0NP_Msk, VADC_G_SEVNP_SEV0NP_Pos,";
  protected final String TEXT_716 = ");   " + NL + " ";
  protected final String TEXT_717 = "\t\t\t\t\t\t      ";
  protected final String TEXT_718 = " ";
  protected final String TEXT_719 = "  ";
  protected final String TEXT_720 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_721 = "->SEVNP, VADC_G_SEVNP_SEV1NP_Msk, VADC_G_SEVNP_SEV1NP_Pos,";
  protected final String TEXT_722 = "); " + NL + "   ";
  protected final String TEXT_723 = "                          ";
  protected final String TEXT_724 = "\t\t\t\t\t\t      ";
  protected final String TEXT_725 = " ";
  protected final String TEXT_726 = "  ";
  protected final String TEXT_727 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_728 = "->SYNCTR, VADC_G_SYNCTR_STSEL_Msk, VADC_G_SYNCTR_STSEL_Pos,";
  protected final String TEXT_729 = "); " + NL + "   ";
  protected final String TEXT_730 = " ";
  protected final String TEXT_731 = "\t\t\t\t\t\t      ";
  protected final String TEXT_732 = " ";
  protected final String TEXT_733 = "  ";
  protected final String TEXT_734 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_735 = "->SYNCTR, VADC_G_SYNCTR_EVALR1_Msk, VADC_G_SYNCTR_EVALR1_Pos,";
  protected final String TEXT_736 = "); " + NL + "   ";
  protected final String TEXT_737 = " ";
  protected final String TEXT_738 = "\t\t\t\t\t\t      ";
  protected final String TEXT_739 = " ";
  protected final String TEXT_740 = "  ";
  protected final String TEXT_741 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_742 = "->SYNCTR, VADC_G_SYNCTR_EVALR2_Msk, VADC_G_SYNCTR_EVALR2_Pos,";
  protected final String TEXT_743 = "); " + NL + "   ";
  protected final String TEXT_744 = " ";
  protected final String TEXT_745 = "\t\t\t\t\t\t      ";
  protected final String TEXT_746 = " ";
  protected final String TEXT_747 = "  ";
  protected final String TEXT_748 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_749 = "->SYNCTR, VADC_G_SYNCTR_EVALR3_Msk, VADC_G_SYNCTR_EVALR3_Pos,";
  protected final String TEXT_750 = "); " + NL + "   ";
  protected final String TEXT_751 = "                           ";
  protected final String TEXT_752 = "\t\t\t\t\t\t      ";
  protected final String TEXT_753 = " ";
  protected final String TEXT_754 = "  ";
  protected final String TEXT_755 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_756 = "->ALIAS, VADC_G_ALIAS_ALIAS0_Msk, VADC_G_ALIAS_ALIAS0_Pos,";
  protected final String TEXT_757 = "); " + NL + "   ";
  protected final String TEXT_758 = "\t\t\t\t\t\t      ";
  protected final String TEXT_759 = " ";
  protected final String TEXT_760 = "  ";
  protected final String TEXT_761 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_762 = "->ALIAS, VADC_G_ALIAS_ALIAS1_Msk, VADC_G_ALIAS_ALIAS1_Pos,";
  protected final String TEXT_763 = "); " + NL + "   ";
  protected final String TEXT_764 = " " + NL + "   \t\t\t\t\t\t\t\t ";
  protected final String TEXT_765 = "\t\t\t\t\t\t      ";
  protected final String TEXT_766 = " ";
  protected final String TEXT_767 = "  ";
  protected final String TEXT_768 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_769 = "->CHCTR[0], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,";
  protected final String TEXT_770 = "); " + NL + "   ";
  protected final String TEXT_771 = " ";
  protected final String TEXT_772 = "\t\t\t\t\t\t      ";
  protected final String TEXT_773 = " ";
  protected final String TEXT_774 = "  ";
  protected final String TEXT_775 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_776 = "->CHCTR[1], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,";
  protected final String TEXT_777 = "); " + NL + "   ";
  protected final String TEXT_778 = " ";
  protected final String TEXT_779 = "\t\t\t\t\t\t      ";
  protected final String TEXT_780 = " ";
  protected final String TEXT_781 = "  ";
  protected final String TEXT_782 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_783 = "->CHCTR[2], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,";
  protected final String TEXT_784 = "); " + NL + "   ";
  protected final String TEXT_785 = " ";
  protected final String TEXT_786 = "\t\t\t\t\t\t      ";
  protected final String TEXT_787 = " ";
  protected final String TEXT_788 = "  ";
  protected final String TEXT_789 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_790 = "->CHCTR[3], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,";
  protected final String TEXT_791 = "); " + NL + "   ";
  protected final String TEXT_792 = " ";
  protected final String TEXT_793 = "\t\t\t\t\t\t      ";
  protected final String TEXT_794 = " ";
  protected final String TEXT_795 = "  ";
  protected final String TEXT_796 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_797 = "->CHCTR[4], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,";
  protected final String TEXT_798 = "); " + NL + "   ";
  protected final String TEXT_799 = " ";
  protected final String TEXT_800 = "\t\t\t\t\t\t      ";
  protected final String TEXT_801 = " ";
  protected final String TEXT_802 = "  ";
  protected final String TEXT_803 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_804 = "->CHCTR[5], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,";
  protected final String TEXT_805 = "); " + NL + "   ";
  protected final String TEXT_806 = " ";
  protected final String TEXT_807 = "\t\t\t\t\t\t      ";
  protected final String TEXT_808 = " ";
  protected final String TEXT_809 = "  ";
  protected final String TEXT_810 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_811 = "->CHCTR[6], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,";
  protected final String TEXT_812 = "); " + NL + "   ";
  protected final String TEXT_813 = " ";
  protected final String TEXT_814 = "\t\t\t\t\t\t      ";
  protected final String TEXT_815 = " ";
  protected final String TEXT_816 = "  ";
  protected final String TEXT_817 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_818 = "->CHCTR[7], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,";
  protected final String TEXT_819 = "); " + NL + "   ";
  protected final String TEXT_820 = "                                                                    ";
  protected final String TEXT_821 = "\t\t\t\t\t\t      ";
  protected final String TEXT_822 = " ";
  protected final String TEXT_823 = "  ";
  protected final String TEXT_824 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_825 = "->CEVNP0, VADC_G_CEVNP0_CEV0NP_Msk, VADC_G_CEVNP0_CEV0NP_Pos,";
  protected final String TEXT_826 = "); " + NL + "   ";
  protected final String TEXT_827 = "                   ";
  protected final String TEXT_828 = "\t\t\t\t\t\t      ";
  protected final String TEXT_829 = " ";
  protected final String TEXT_830 = "  ";
  protected final String TEXT_831 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_832 = "->CEVNP0, VADC_G_CEVNP0_CEV1NP_Msk, VADC_G_CEVNP0_CEV1NP_Pos,";
  protected final String TEXT_833 = "); " + NL + "   ";
  protected final String TEXT_834 = "                 ";
  protected final String TEXT_835 = "\t\t\t\t\t\t      ";
  protected final String TEXT_836 = " ";
  protected final String TEXT_837 = "  ";
  protected final String TEXT_838 = "      " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_839 = "->CEVNP0, VADC_G_CEVNP0_CEV2NP_Msk, VADC_G_CEVNP0_CEV2NP_Pos,";
  protected final String TEXT_840 = "); " + NL + "   ";
  protected final String TEXT_841 = "                   ";
  protected final String TEXT_842 = "\t\t\t\t\t\t      ";
  protected final String TEXT_843 = " ";
  protected final String TEXT_844 = "  ";
  protected final String TEXT_845 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_846 = "->CEVNP0, VADC_G_CEVNP0_CEV3NP_Msk, VADC_G_CEVNP0_CEV3NP_Pos,";
  protected final String TEXT_847 = "); " + NL + "   ";
  protected final String TEXT_848 = "                    ";
  protected final String TEXT_849 = "\t\t\t\t\t\t      ";
  protected final String TEXT_850 = " ";
  protected final String TEXT_851 = "  ";
  protected final String TEXT_852 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_853 = "->CEVNP0, VADC_G_CEVNP0_CEV4NP_Msk, VADC_G_CEVNP0_CEV4NP_Pos,";
  protected final String TEXT_854 = "); " + NL + "   ";
  protected final String TEXT_855 = "                 ";
  protected final String TEXT_856 = "\t\t\t\t\t\t      ";
  protected final String TEXT_857 = " ";
  protected final String TEXT_858 = "  ";
  protected final String TEXT_859 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_860 = "->CEVNP0, VADC_G_CEVNP0_CEV5NP_Msk, VADC_G_CEVNP0_CEV5NP_Pos,";
  protected final String TEXT_861 = "); " + NL + "   ";
  protected final String TEXT_862 = "                    ";
  protected final String TEXT_863 = "\t\t\t\t\t\t      ";
  protected final String TEXT_864 = " ";
  protected final String TEXT_865 = "  ";
  protected final String TEXT_866 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_867 = "->CEVNP0, VADC_G_CEVNP0_CEV6NP_Msk, VADC_G_CEVNP0_CEV6NP_Pos,";
  protected final String TEXT_868 = "); " + NL + "   ";
  protected final String TEXT_869 = "                  ";
  protected final String TEXT_870 = "\t\t\t\t\t\t      ";
  protected final String TEXT_871 = " ";
  protected final String TEXT_872 = "  ";
  protected final String TEXT_873 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_874 = "->CEVNP0, VADC_G_CEVNP0_CEV7NP_Msk, VADC_G_CEVNP0_CEV7NP_Pos,";
  protected final String TEXT_875 = "); " + NL + "   ";
  protected final String TEXT_876 = "                 ";
  protected final String TEXT_877 = "\t\t\t\t\t\t      ";
  protected final String TEXT_878 = " ";
  protected final String TEXT_879 = "  ";
  protected final String TEXT_880 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_881 = "->REVNP0, VADC_G_REVNP0_REV0NP_Msk, VADC_G_REVNP0_REV0NP_Pos,";
  protected final String TEXT_882 = "); " + NL + "   ";
  protected final String TEXT_883 = "                   ";
  protected final String TEXT_884 = "\t\t\t\t\t\t      ";
  protected final String TEXT_885 = " ";
  protected final String TEXT_886 = "  ";
  protected final String TEXT_887 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_888 = "->REVNP0, VADC_G_REVNP0_REV1NP_Msk, VADC_G_REVNP0_REV1NP_Pos,";
  protected final String TEXT_889 = "); " + NL + "   ";
  protected final String TEXT_890 = "           ";
  protected final String TEXT_891 = "\t\t\t\t\t\t      ";
  protected final String TEXT_892 = " ";
  protected final String TEXT_893 = "  ";
  protected final String TEXT_894 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_895 = "->REVNP0, VADC_G_REVNP0_REV2NP_Msk, VADC_G_REVNP0_REV2NP_Pos,";
  protected final String TEXT_896 = "); " + NL + "   ";
  protected final String TEXT_897 = "                ";
  protected final String TEXT_898 = "\t\t\t\t\t\t      ";
  protected final String TEXT_899 = " ";
  protected final String TEXT_900 = "  ";
  protected final String TEXT_901 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_902 = "->REVNP0, VADC_G_REVNP0_REV3NP_Msk, VADC_G_REVNP0_REV3NP_Pos,";
  protected final String TEXT_903 = "); " + NL + "   ";
  protected final String TEXT_904 = "                ";
  protected final String TEXT_905 = "\t\t\t\t\t\t      ";
  protected final String TEXT_906 = " ";
  protected final String TEXT_907 = "  ";
  protected final String TEXT_908 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_909 = "->REVNP0, VADC_G_REVNP0_REV4NP_Msk, VADC_G_REVNP0_REV4NP_Pos,";
  protected final String TEXT_910 = "); " + NL + "   ";
  protected final String TEXT_911 = "              ";
  protected final String TEXT_912 = "\t\t\t\t\t\t      ";
  protected final String TEXT_913 = " ";
  protected final String TEXT_914 = "  ";
  protected final String TEXT_915 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_916 = "->REVNP0, VADC_G_REVNP0_REV5NP_Msk, VADC_G_REVNP0_REV5NP_Pos,";
  protected final String TEXT_917 = "); " + NL + "   ";
  protected final String TEXT_918 = "              ";
  protected final String TEXT_919 = "\t\t\t\t\t\t      ";
  protected final String TEXT_920 = " ";
  protected final String TEXT_921 = "  ";
  protected final String TEXT_922 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_923 = "->REVNP0, VADC_G_REVNP0_REV6NP_Msk, VADC_G_REVNP0_REV6NP_Pos,";
  protected final String TEXT_924 = "); " + NL + "   ";
  protected final String TEXT_925 = "                 ";
  protected final String TEXT_926 = "\t\t\t\t\t\t      ";
  protected final String TEXT_927 = " ";
  protected final String TEXT_928 = "  ";
  protected final String TEXT_929 = NL + "  WR_REG(VADC_G";
  protected final String TEXT_930 = "->REVNP0, VADC_G_REVNP0_REV7NP_Msk, VADC_G_REVNP0_REV7NP_Pos,";
  protected final String TEXT_931 = "); " + NL + "   ";
  protected final String TEXT_932 = "                 ";
  protected final String TEXT_933 = "\t\t\t\t\t\t      ";
  protected final String TEXT_934 = " ";
  protected final String TEXT_935 = "  ";
  protected final String TEXT_936 = "   " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_937 = "->REVNP1, VADC_G_REVNP1_REV8NP_Msk, VADC_G_REVNP1_REV8NP_Pos,";
  protected final String TEXT_938 = "); " + NL + "   ";
  protected final String TEXT_939 = "                                ";
  protected final String TEXT_940 = "\t\t\t\t\t\t      ";
  protected final String TEXT_941 = " ";
  protected final String TEXT_942 = "  ";
  protected final String TEXT_943 = " " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_944 = "->REVNP1, VADC_G_REVNP1_REV9NP_Msk, VADC_G_REVNP1_REV9NP_Pos,";
  protected final String TEXT_945 = "); " + NL + "   ";
  protected final String TEXT_946 = "                    ";
  protected final String TEXT_947 = "\t\t\t\t\t\t      ";
  protected final String TEXT_948 = " ";
  protected final String TEXT_949 = "  ";
  protected final String TEXT_950 = "     " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_951 = "->REVNP1, VADC_G_REVNP1_REV10NP_Msk, VADC_G_REVNP1_REV10NP_Pos,";
  protected final String TEXT_952 = "); " + NL + "   ";
  protected final String TEXT_953 = "               ";
  protected final String TEXT_954 = "\t\t\t\t\t\t      ";
  protected final String TEXT_955 = " ";
  protected final String TEXT_956 = "  ";
  protected final String TEXT_957 = "      " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_958 = "->REVNP1, VADC_G_REVNP1_REV11NP_Msk, VADC_G_REVNP1_REV11NP_Pos,";
  protected final String TEXT_959 = "); " + NL + "   ";
  protected final String TEXT_960 = "                   ";
  protected final String TEXT_961 = "\t\t\t\t\t\t      ";
  protected final String TEXT_962 = " ";
  protected final String TEXT_963 = "  ";
  protected final String TEXT_964 = "   " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_965 = "->REVNP1, VADC_G_REVNP1_REV12NP_Msk, VADC_G_REVNP1_REV12NP_Pos,";
  protected final String TEXT_966 = "); " + NL + "   ";
  protected final String TEXT_967 = "            ";
  protected final String TEXT_968 = "\t\t\t\t\t\t      ";
  protected final String TEXT_969 = " ";
  protected final String TEXT_970 = "  ";
  protected final String TEXT_971 = "     " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_972 = "->REVNP1, VADC_G_REVNP1_REV13NP_Msk, VADC_G_REVNP1_REV13NP_Pos,";
  protected final String TEXT_973 = "); " + NL + "   ";
  protected final String TEXT_974 = "                ";
  protected final String TEXT_975 = "\t\t\t\t\t\t      ";
  protected final String TEXT_976 = " ";
  protected final String TEXT_977 = "  ";
  protected final String TEXT_978 = " " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_979 = "->REVNP1, VADC_G_REVNP1_REV14NP_Msk, VADC_G_REVNP1_REV14NP_Pos,";
  protected final String TEXT_980 = "); " + NL + "   ";
  protected final String TEXT_981 = "              ";
  protected final String TEXT_982 = "\t\t\t\t\t\t      ";
  protected final String TEXT_983 = " ";
  protected final String TEXT_984 = "  ";
  protected final String TEXT_985 = "      " + NL + "  WR_REG(VADC_G";
  protected final String TEXT_986 = "->REVNP1, VADC_G_REVNP1_REV15NP_Msk, VADC_G_REVNP1_REV15NP_Pos,";
  protected final String TEXT_987 = "); " + NL + "   ";
  protected final String TEXT_988 = "                      ";
  protected final String TEXT_989 = "  " + NL + "               /*VADC GLOBAL RESULT Mux Related SFR/Bitfields Configurations*/  ";
  protected final String TEXT_990 = "\t\t\t\t\t\t      ";
  protected final String TEXT_991 = " ";
  protected final String TEXT_992 = "  ";
  protected final String TEXT_993 = " " + NL + "  WR_REG(VADC->GLOBEVNP, VADC_GLOBEVNP_REV0NP_Msk, VADC_GLOBEVNP_REV0NP_Pos,";
  protected final String TEXT_994 = "); " + NL + "   ";
  protected final String TEXT_995 = "              ";
  protected final String TEXT_996 = "\t\t\t\t\t\t      ";
  protected final String TEXT_997 = " ";
  protected final String TEXT_998 = "  ";
  protected final String TEXT_999 = "   " + NL + "  WR_REG(VADC->EMUXSEL, VADC_EMUXSEL_EMUXGRP0_Msk, VADC_EMUXSEL_EMUXGRP0_Pos,";
  protected final String TEXT_1000 = "); " + NL + "   ";
  protected final String TEXT_1001 = "            ";
  protected final String TEXT_1002 = "\t\t\t\t\t\t      ";
  protected final String TEXT_1003 = " ";
  protected final String TEXT_1004 = "  ";
  protected final String TEXT_1005 = "  " + NL + "  WR_REG(VADC->EMUXSEL, VADC_EMUXSEL_EMUXGRP1_Msk, VADC_EMUXSEL_EMUXGRP1_Pos,";
  protected final String TEXT_1006 = "); " + NL + "   ";
  protected final String TEXT_1007 = "                        " + NL + "               /*VADC BACKGROUND Source Mux Related SFR/Bitfields Configurations*/  ";
  protected final String TEXT_1008 = "\t\t\t\t\t\t      ";
  protected final String TEXT_1009 = " ";
  protected final String TEXT_1010 = "  ";
  protected final String TEXT_1011 = "     " + NL + "  WR_REG(VADC->BRSCTRL, VADC_BRSCTRL_XTWC_XTSEL_Msk, VADC_BRSCTRL_XTSEL_Pos, \\" + NL + "   (((((VADC->BRSCTRL) & VADC_BRSCTRL_XTMODE_Msk) | VADC_BRSCTRL_XTWC_Msk) >> VADC_BRSCTRL_XTSEL_Pos) | ";
  protected final String TEXT_1012 = "));" + NL;
  protected final String TEXT_1013 = "         ";
  protected final String TEXT_1014 = "\t\t\t\t\t\t      ";
  protected final String TEXT_1015 = " ";
  protected final String TEXT_1016 = "  ";
  protected final String TEXT_1017 = "    " + NL + "  WR_REG(VADC->BRSCTRL, VADC_BRSCTRL_GTWC_GTSEL_Msk, VADC_BRSCTRL_GTSEL_Pos, \\" + NL + "   (((VADC_BRSCTRL_GTWC_Msk) >> VADC_BRSCTRL_GTSEL_Pos) | ";
  protected final String TEXT_1018 = ")); " + NL;
  protected final String TEXT_1019 = "       ";
  protected final String TEXT_1020 = "\t\t\t\t\t\t      ";
  protected final String TEXT_1021 = " ";
  protected final String TEXT_1022 = "                 ";
  protected final String TEXT_1023 = "  " + NL + "  WR_REG(VADC->GLOBEVNP, VADC_GLOBEVNP_SEV0NP_Msk, VADC_GLOBEVNP_SEV0NP_Pos,";
  protected final String TEXT_1024 = "); " + NL + "   ";
  protected final String TEXT_1025 = "                       ";
  protected final String TEXT_1026 = "   ";
  protected final String TEXT_1027 = "  ";
  protected final String TEXT_1028 = "    ";
  protected final String TEXT_1029 = NL + "       /*        DAC Macro definitions     */               ";
  protected final String TEXT_1030 = NL + "            " + NL + "  WR_REG(DAC->DAC";
  protected final String TEXT_1031 = "CFG1, DAC_DAC";
  protected final String TEXT_1032 = "CFG1_TRIGSEL_Msk, DAC_DAC";
  protected final String TEXT_1033 = "CFG1_TRIGSEL_Pos, VALUE";
  protected final String TEXT_1034 = ");                /*    DAC->DAC";
  protected final String TEXT_1035 = "CFG1_TRIGSEL */";
  protected final String TEXT_1036 = " ";
  protected final String TEXT_1037 = "    ";
  protected final String TEXT_1038 = "    ";
  protected final String TEXT_1039 = NL + "       /*        SCU Macro definitions     */               ";
  protected final String TEXT_1040 = NL + NL + "  WR_REGHIB(SCU_HIBERNATE->HDCR, SCU_HIBERNATE_HDCR_GPI0SEL_Msk, SCU_HIBERNATE_HDCR_GPI0SEL_Pos, VALUE";
  protected final String TEXT_1041 = ");                /*    SCU_HIBERNATE->HDCR_GPI0SEL */        ";
  protected final String TEXT_1042 = NL + "        " + NL + "  WR_REGHIB(SCU_HIBERNATE->HDCR, SCU_HIBERNATE_HDCR_WKUPSEL_Msk, SCU_HIBERNATE_HDCR_WKUPSEL_Pos, VALUE";
  protected final String TEXT_1043 = ");                /*    SCU_HIBERNATE->HDCR_WKUPSEL */";
  protected final String TEXT_1044 = NL + NL + "  WR_REGHIB(SCU_HIBERNATE->HDCR, SCU_HIBERNATE_HDCR_HIBIO";
  protected final String TEXT_1045 = "SEL_OE_Msk, SCU_HIBERNATE_HDCR_HIBIO";
  protected final String TEXT_1046 = "SEL_OE_Pos, PORT_IOCR_OE";
  protected final String TEXT_1047 = ", SCU_INTERRUPT_SRRAW_HDCR_Msk);                /*    SCU_HIBERNATE->HDCR_HIBIO";
  protected final String TEXT_1048 = "SEL_OE */        ";
  protected final String TEXT_1049 = NL + "        " + NL + "  WR_REGHIB(SCU_HIBERNATE->HDCR, SCU_HIBERNATE_HDCR_HIBIO";
  protected final String TEXT_1050 = "SEL_PCR_Msk, SCU_HIBERNATE_HDCR_HIBIO";
  protected final String TEXT_1051 = "SEL_PCR_Pos, PORT_IOCR_PCR";
  protected final String TEXT_1052 = ", SCU_INTERRUPT_SRRAW_HDCR_Msk);                /*    SCU_HIBERNATE->HDCR_HIBIO";
  protected final String TEXT_1053 = "SEL_PCR */";
  protected final String TEXT_1054 = NL + "        " + NL + "  WR_REG(SCU_INTERRUPT->NMIREQEN, SCU_INTERRUPT_NMIREQEN_PRWARN_Msk, SCU_INTERRUPT_NMIREQEN_PRWARN_Pos, VALUE";
  protected final String TEXT_1055 = ");                /*    SCU_INTERRUPT->NMIREQEN_PRWARN */";
  protected final String TEXT_1056 = NL + "            " + NL + "  WR_REG(SCU_INTERRUPT->NMIREQEN, SCU_INTERRUPT_NMIREQEN_PI_Msk, SCU_INTERRUPT_NMIREQEN_PI_Pos, VALUE";
  protected final String TEXT_1057 = ");                /*    SCU_INTERRUPT->NMIREQEN_PI */";
  protected final String TEXT_1058 = NL + "        " + NL + "  WR_REG(SCU_INTERRUPT->NMIREQEN, SCU_INTERRUPT_NMIREQEN_AI_Msk, SCU_INTERRUPT_NMIREQEN_AI_Pos, VALUE";
  protected final String TEXT_1059 = ");                /*    SCU_INTERRUPT->NMIREQEN_AI */";
  protected final String TEXT_1060 = NL + "        " + NL + "  WR_REG(SCU_INTERRUPT->NMIREQEN, SCU_INTERRUPT_NMIREQEN_ERU0";
  protected final String TEXT_1061 = "_Msk, SCU_INTERRUPT_NMIREQEN_ERU0";
  protected final String TEXT_1062 = "_Pos, VALUE";
  protected final String TEXT_1063 = ");                /*    SCU_INTERRUPT->NMIREQEN_ERU0";
  protected final String TEXT_1064 = " */" + NL + "\t\t\t";
  protected final String TEXT_1065 = " ";
  protected final String TEXT_1066 = "    ";
  protected final String TEXT_1067 = NL + "       /*        SCU Macro definitions     */  ";
  protected final String TEXT_1068 = NL + "                  SCU_GENERAL->PASSWD = 0x000000C0UL;" + NL + "  WR_REG(SCU_CLK->CLKCR, SCU_CLK_CLKCR_RTCCLKSEL_Msk, SCU_CLK_CLKCR_RTCCLKSEL_Pos, ";
  protected final String TEXT_1069 = ");                /*    SCU_CLOCK->CLKCR_RTCCLKSEL */" + NL + "                  SCU_GENERAL->PASSWD = 0x000000C3UL;" + NL + "\t\t\t\t";
  protected final String TEXT_1070 = NL + NL + "  WR_REG(COMPARATOR->ANACMP0, COMPARATOR_ANACMP0_ACMP0_SEL_Msk, COMPARATOR_ANACMP0_ACMP0_SEL_Pos, ";
  protected final String TEXT_1071 = ");                /*    COMPARATOR->ANACMP0_ACMP0_SEL */";
  protected final String TEXT_1072 = NL + NL + "  WR_REG(COMPARATOR->ANACMP1, COMPARATOR_ANACMP1_REF_DIV_EN_Msk, COMPARATOR_ANACMP1_REF_DIV_EN_Pos, ";
  protected final String TEXT_1073 = ");                /*    COMPARATOR->ANACMP1_REF_DIV_EN */";
  protected final String TEXT_1074 = NL + NL + "  WR_REG(COMPARATOR->ANACMP2, COMPARATOR_ANACMP2_ACMP2_SEL_Msk, COMPARATOR_ANACMP2_ACMP2_SEL_Pos, ";
  protected final String TEXT_1075 = ");                /*    COMPARATOR->ANACMP2_ACMP2_SEL */";
  protected final String TEXT_1076 = "    ";
  protected final String TEXT_1077 = NL + "/*        LEDTS Macro definitions:         */  ";
  protected final String TEXT_1078 = NL + NL + "  WR_REG(LEDTS1->GLOBCTL, LEDTS_GLOBCTL_CLK_PS_Msk, LEDTS_GLOBCTL_CLK_PS_Pos, 0);                \t\t\t\t\t\t\t\t/*    LEDTS1->GLOBCTL_CLK_PS */" + NL + "  WR_REG(LEDTS1->GLOBCTL, LEDTS_GLOBCTL_ENSYNC_Msk, LEDTS_GLOBCTL_ENSYNC_Pos, ";
  protected final String TEXT_1079 = ");                /*    LEDTS1->GLOBCTL_ENSYNC */";
  protected final String TEXT_1080 = "    ";
  protected final String TEXT_1081 = NL + "/*        BCCU Macro definitions:         */ ";
  protected final String TEXT_1082 = NL + NL + "  WR_REG(BCCU0_CH";
  protected final String TEXT_1083 = "->CHCONFIG, BCCU_CH_CHCONFIG_DSEL_Msk, BCCU_CH_CHCONFIG_DSEL_Pos, ";
  protected final String TEXT_1084 = ");                /*    BCCU_CHCONFIG";
  protected final String TEXT_1085 = "_DSEL */";
  protected final String TEXT_1086 = NL + NL + "  WR_REG(BCCU0->GLOBCON, BCCU_GLOBCON_TRAPIS_Msk, BCCU_GLOBCON_TRAPIS_Pos, ";
  protected final String TEXT_1087 = ");                /*    BCCU_GLOBCON_TRAPIS */";
  protected final String TEXT_1088 = "    ";
  protected final String TEXT_1089 = "  " + NL + "/*        ERU";
  protected final String TEXT_1090 = " Macro definitions:         */  ";
  protected final String TEXT_1091 = NL + NL + "  WR_REG(ERU";
  protected final String TEXT_1092 = "->EXISEL, ERU_EXISEL_EXS";
  protected final String TEXT_1093 = "A_Msk, ERU_EXISEL_EXS";
  protected final String TEXT_1094 = "A_Pos, SIGNAL_ERU_xA";
  protected final String TEXT_1095 = ");                /*    ERU";
  protected final String TEXT_1096 = "_EXISEL_EXS";
  protected final String TEXT_1097 = "A */";
  protected final String TEXT_1098 = NL + NL + "  WR_REG(ERU";
  protected final String TEXT_1099 = "->EXISEL, ERU_EXISEL_EXS";
  protected final String TEXT_1100 = "B_Msk, ERU_EXISEL_EXS";
  protected final String TEXT_1101 = "B_Pos, SIGNAL_ERU_xB";
  protected final String TEXT_1102 = ");                /*    ERU";
  protected final String TEXT_1103 = "_EXISEL_EXS";
  protected final String TEXT_1104 = "B */";
  protected final String TEXT_1105 = NL + NL + "  WR_REG(ERU";
  protected final String TEXT_1106 = "->EXICON[";
  protected final String TEXT_1107 = "], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR";
  protected final String TEXT_1108 = ");                            /*    ERU";
  protected final String TEXT_1109 = "_EXICON[";
  protected final String TEXT_1110 = "]_PE */";
  protected final String TEXT_1111 = NL + NL + "  WR_REG(ERU";
  protected final String TEXT_1112 = "->EXICON[";
  protected final String TEXT_1113 = "], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, SIGNAL_TRx";
  protected final String TEXT_1114 = ");                        /*    ERU";
  protected final String TEXT_1115 = "_EXICON[";
  protected final String TEXT_1116 = "]_OCS */";
  protected final String TEXT_1117 = NL + "        " + NL + "  WR_REG(ERU";
  protected final String TEXT_1118 = "->EXOCON[";
  protected final String TEXT_1119 = "], ERU_EXOCON_IPEN";
  protected final String TEXT_1120 = "_Msk, ERU_EXOCON_IPEN";
  protected final String TEXT_1121 = "_Pos, SIGNAL_ERS_ETL_FL";
  protected final String TEXT_1122 = ");            /*    ERU";
  protected final String TEXT_1123 = "_EXOCON[";
  protected final String TEXT_1124 = "]_IPEN";
  protected final String TEXT_1125 = " */";
  protected final String TEXT_1126 = NL + "    " + NL + "  WR_REG(ERU";
  protected final String TEXT_1127 = "->EXOCON[";
  protected final String TEXT_1128 = "], ERU_EXOCON_ISS_Msk, ERU_EXOCON_ISS_Pos, SIGNAL_ERU_OGU_y";
  protected final String TEXT_1129 = ");                    /*    ERU";
  protected final String TEXT_1130 = "_EXOCON[";
  protected final String TEXT_1131 = "]_ISS */";
  protected final String TEXT_1132 = NL + NL + "/*        PORT Macro definitions for IOCR_OE, IOCR_PCR & HWSEL_HW     */               ";
  protected final String TEXT_1133 = NL + "           " + NL + "  WR_REG(PORT";
  protected final String TEXT_1134 = "->PDISC, PORT";
  protected final String TEXT_1135 = "_PDISC_PDIS";
  protected final String TEXT_1136 = "_Msk, PORT";
  protected final String TEXT_1137 = "_PDISC_PDIS";
  protected final String TEXT_1138 = "_Pos, PORT_PDISC_PDIS";
  protected final String TEXT_1139 = ");            /*    P";
  protected final String TEXT_1140 = ".";
  protected final String TEXT_1141 = " : PORT";
  protected final String TEXT_1142 = "_PDISC_PDIS";
  protected final String TEXT_1143 = " */";
  protected final String TEXT_1144 = NL + "           " + NL + "  WR_REG(PORT";
  protected final String TEXT_1145 = "->HWSEL, PORT";
  protected final String TEXT_1146 = "_HWSEL_HW";
  protected final String TEXT_1147 = "_Msk, PORT";
  protected final String TEXT_1148 = "_HWSEL_HW";
  protected final String TEXT_1149 = "_Pos, PORT_HWSEL_HW";
  protected final String TEXT_1150 = ");                    /*    P";
  protected final String TEXT_1151 = ".";
  protected final String TEXT_1152 = " : PORT";
  protected final String TEXT_1153 = "_HWSEL_HW";
  protected final String TEXT_1154 = " */  ";
  protected final String TEXT_1155 = " " + NL + "              " + NL + "  WR_REG(PORT";
  protected final String TEXT_1156 = "->HWSEL, PORT";
  protected final String TEXT_1157 = "_HWSEL_HW";
  protected final String TEXT_1158 = "_Msk, PORT";
  protected final String TEXT_1159 = "_HWSEL_HW";
  protected final String TEXT_1160 = "_Pos, PORT_HWSEL_SW);                    /*    P";
  protected final String TEXT_1161 = ".";
  protected final String TEXT_1162 = " : PORT";
  protected final String TEXT_1163 = "_HWSEL_HW";
  protected final String TEXT_1164 = " */  ";
  protected final String TEXT_1165 = NL + "           " + NL + "  WR_REG(PORT";
  protected final String TEXT_1166 = "->IOCR";
  protected final String TEXT_1167 = ", PORT_IOCR_PC";
  protected final String TEXT_1168 = "_PCR_Msk, PORT_IOCR_PC";
  protected final String TEXT_1169 = "_PCR_Pos, PORT_IOCR_PCR";
  protected final String TEXT_1170 = ");            /*    P";
  protected final String TEXT_1171 = ".";
  protected final String TEXT_1172 = " : PORT";
  protected final String TEXT_1173 = "_IOCR";
  protected final String TEXT_1174 = "_PC";
  protected final String TEXT_1175 = "_PCR */";
  protected final String TEXT_1176 = NL + NL + "  WR_REG(PORT";
  protected final String TEXT_1177 = "->IOCR";
  protected final String TEXT_1178 = ", PORT_IOCR_PC";
  protected final String TEXT_1179 = "_OE_Msk, PORT_IOCR_PC";
  protected final String TEXT_1180 = "_OE_Pos, PORT_IOCR_OE";
  protected final String TEXT_1181 = ");                /*    P";
  protected final String TEXT_1182 = ".";
  protected final String TEXT_1183 = " : PORT";
  protected final String TEXT_1184 = "_IOCR";
  protected final String TEXT_1185 = "_PC";
  protected final String TEXT_1186 = "_OE */\t\t\t\t\t   ";
  protected final String TEXT_1187 = "    ";
  protected final String TEXT_1188 = NL + "}" + NL + "" + NL + "" + NL + "/*******************************************************************************" + NL + "** Syntax           : void DAVE_MUX_PreInit(void)                             **" + NL + "**                                                                            **" + NL + "** Reentrancy       : None                                                    **" + NL + "**                                                                            **" + NL + "** Parameters (in)  : void                                                    **" + NL + "**                                                                            **" + NL + "** Parameters (out) : none                                                    **" + NL + "**                                                                            **" + NL + "** Return value     : none                                                    **" + NL + "**                                                                            **" + NL + "** Description      : This is the Mux configuration                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + " " + NL + "void DAVE_MUX_PreInit(void)" + NL + "{";
  protected final String TEXT_1189 = NL + NL + "/*        PORT Macro definitions for IOCR_OE, IOCR_PCR & HWSEL_HW     */               ";
  protected final String TEXT_1190 = NL + "           " + NL + "  WR_REG(PORT";
  protected final String TEXT_1191 = "->PDISC, PORT";
  protected final String TEXT_1192 = "_PDISC_PDIS";
  protected final String TEXT_1193 = "_Msk, PORT";
  protected final String TEXT_1194 = "_PDISC_PDIS";
  protected final String TEXT_1195 = "_Pos, PORT_PDISC_PDIS";
  protected final String TEXT_1196 = ");            /*    P";
  protected final String TEXT_1197 = ".";
  protected final String TEXT_1198 = " : PORT";
  protected final String TEXT_1199 = "_PDISC_PDIS";
  protected final String TEXT_1200 = " */";
  protected final String TEXT_1201 = NL + "           " + NL + "  WR_REG(PORT";
  protected final String TEXT_1202 = "->HWSEL, PORT";
  protected final String TEXT_1203 = "_HWSEL_HW";
  protected final String TEXT_1204 = "_Msk, PORT";
  protected final String TEXT_1205 = "_HWSEL_HW";
  protected final String TEXT_1206 = "_Pos, PORT_HWSEL_HW";
  protected final String TEXT_1207 = ");                    /*    P";
  protected final String TEXT_1208 = ".";
  protected final String TEXT_1209 = " : PORT";
  protected final String TEXT_1210 = "_HWSEL_HW";
  protected final String TEXT_1211 = " */  ";
  protected final String TEXT_1212 = " " + NL + "              " + NL + "  WR_REG(PORT";
  protected final String TEXT_1213 = "->HWSEL, PORT";
  protected final String TEXT_1214 = "_HWSEL_HW";
  protected final String TEXT_1215 = "_Msk, PORT";
  protected final String TEXT_1216 = "_HWSEL_HW";
  protected final String TEXT_1217 = "_Pos, PORT_HWSEL_SW);                    /*    P";
  protected final String TEXT_1218 = ".";
  protected final String TEXT_1219 = " : PORT";
  protected final String TEXT_1220 = "_HWSEL_HW";
  protected final String TEXT_1221 = " */  ";
  protected final String TEXT_1222 = "    ";
  protected final String TEXT_1223 = NL + "}";
  protected final String TEXT_1224 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
     int xmc4Device = -1;
   xmc4Device = ((app.getSoftwareId().substring(0,1).compareTo("4")==0)?1:0);
   int xmc1Device = -1;
   xmc1Device = ((app.getSoftwareId().substring(0,1).compareTo("1")==0)?1:0); 
    stringBuffer.append(TEXT_1);
     String TempPeri = null;
  String MyPeriName = null;
  String MyTempPeriName = null;
  Object MyObj = null;     
 ArrayList<String> peri; 
 peri=(ArrayList<String>)(app.getPeripherals());
 HashMap PeriHashMap = new HashMap();  
     for (int k = 0; k < peri.size(); k++) {
         TempPeri = peri.get(k); 
         if (TempPeri.indexOf("/peripheral/") > 0 ){ MyPeriName = TempPeri.substring(TempPeri.indexOf("/peripheral/") + 1, TempPeri.lastIndexOf("/"));} else 
         if (TempPeri.indexOf("/port/") > 0 ){ MyPeriName = TempPeri.substring(TempPeri.indexOf("/port/") + 1, TempPeri.lastIndexOf("/"));}
         PeriHashMap.put(MyPeriName,k); 
    } 
   Set set = PeriHashMap.entrySet(); 
   Iterator i = set.iterator();
     while(i.hasNext()) { 
     Map.Entry peri_me = (Map.Entry)i.next();  
           MyObj = peri_me.getKey();              
           MyTempPeriName = MyObj.toString(); 
    
           
     //********* Capture/Compare Unit 4 (CAPCOM4) CONFIGURATIONS --- BEGIN ************************* 
     if(MyTempPeriName.compareTo("peripheral/ccu4") == 0) {
         String uriStr_CCU4 = "peripheral/ccu4/"; 
    stringBuffer.append(TEXT_2);
     for (int Module = 0; Module < 4; Module++) { 
               String StrTempCC4Reset = null; 
               String StrTempCC4Actual = null; 
               String uriStrTemp = null;        
               uriStrTemp = uriStr_CCU4+ Module +"/global/gctrl_pcis";
               StrTempCC4Reset = app.getResetValue(uriStrTemp);  StrTempCC4Actual = app.getMuxValue(uriStrTemp);              
               if(StrTempCC4Reset.compareTo(StrTempCC4Actual) < 0) {
    stringBuffer.append(TEXT_3);
    stringBuffer.append(Module);
    stringBuffer.append(TEXT_4);
    stringBuffer.append(StrTempCC4Actual);
    stringBuffer.append(TEXT_5);
     } 
                 for (int Slice = 0; Slice < 4; Slice++) { 
                       String tempStrEv0is = null;                    
                       String tempStrEv1is = null;                    
                       String tempStrEv2is = null;                    
                       String StrTempCC4ActualX = null; 
                       String StrTempCC4ActualY = null; 
                       String StrTempCC4ActualZ = null; 
                       String uriStr_Ev0is = null; 
                       String uriStr_Ev1is = null; 
                       String uriStr_Ev2is = null; 
                       String uriStr_Slice = null; 
                       uriStr_Slice = Integer.toString(Module) +"/cc4/"+ Integer.toString(Slice) +"/cc4"+ Integer.toString(Slice);
                       uriStr_Ev0is = uriStr_CCU4 + uriStr_Slice +"ins_ev0is";
                       StrTempCC4Reset = app.getResetValue(uriStr_Ev0is);
                       StrTempCC4ActualX = app.getMuxValue(uriStr_Ev0is);                   
                       if(StrTempCC4Reset.compareTo(StrTempCC4ActualX) < 0) {
                        tempStrEv0is = "WR_REG(CCU4"+ Integer.toString(Module) +"_CC4"+ Integer.toString(Slice) +"->INS, CCU4_CC4_INS_EV0IS_Msk, CCU4_CC4_INS_EV0IS_Pos, CCU4xINy" + (char)(Integer.parseInt(StrTempCC4ActualX.trim()) + 65) + ");";
                       } 
                       uriStr_Ev1is = uriStr_CCU4 + uriStr_Slice +"ins_ev1is";
                       StrTempCC4Reset = app.getResetValue(uriStr_Ev1is); 
                       StrTempCC4ActualY = app.getMuxValue(uriStr_Ev1is);                   
                       if (StrTempCC4Reset.compareTo(StrTempCC4ActualY) < 0) {
                            tempStrEv1is = "WR_REG(CCU4"+ Integer.toString(Module) +"_CC4"+ Integer.toString(Slice) +"->INS, CCU4_CC4_INS_EV1IS_Msk, CCU4_CC4_INS_EV1IS_Pos, CCU4xINy" + (char)(Integer.parseInt(StrTempCC4ActualY.trim()) + 65) + ");"; 
                       }  
                       uriStr_Ev2is = uriStr_CCU4 + uriStr_Slice +"ins_ev2is";
                       StrTempCC4Reset = app.getResetValue(uriStr_Ev2is);
                       StrTempCC4ActualZ = app.getMuxValue(uriStr_Ev2is);               
                       if (StrTempCC4Reset.compareTo(StrTempCC4ActualZ) < 0) {
                         tempStrEv2is = "WR_REG(CCU4"+ Integer.toString(Module) +"_CC4"+ Integer.toString(Slice) +"->INS, CCU4_CC4_INS_EV2IS_Msk, CCU4_CC4_INS_EV2IS_Pos, CCU4xINy" + (char)(Integer.parseInt(StrTempCC4ActualZ.trim()) + 65) + ");"; 
                       } 
                       if((tempStrEv0is != null) | (tempStrEv1is != null) | (tempStrEv2is != null) ){
    stringBuffer.append(TEXT_6);
    stringBuffer.append(Module);
    stringBuffer.append(TEXT_7);
    stringBuffer.append(Slice);
    stringBuffer.append(TEXT_8);
     if(tempStrEv0is != null){
    stringBuffer.append(TEXT_9);
    stringBuffer.append(TEXT_10);
    stringBuffer.append( tempStrEv0is);
    stringBuffer.append(TEXT_11);
     } 
                           if(tempStrEv1is != null){
    stringBuffer.append(TEXT_12);
    stringBuffer.append(TEXT_13);
    stringBuffer.append( tempStrEv1is);
    stringBuffer.append(TEXT_14);
     } 
                           if(tempStrEv2is != null){
    stringBuffer.append(TEXT_15);
    stringBuffer.append(TEXT_16);
    stringBuffer.append( tempStrEv2is);
    stringBuffer.append(TEXT_17);
     }
                     } 
             }             
                 for (int Slice = 0; Slice < 4; Slice++) { 
                       String tempStr_posr = null;                    
                       String tempStr_cmsr = null;                    
                       String tempStr_e0sr = null;                    
                       String tempStr_e1sr = null;                    
                       String tempStr_e2sr = null;                    
                       String StrTempCC4ActualX = null; 
                       String StrTempCC4ActualY = null; 
                       String StrTempCC4Actual_e0sr = null; 
                       String StrTempCC4Actual_e1sr = null; 
                       String StrTempCC4Actual_e2sr = null; 
                       String uriStr_posr = null; 
                       String uriStr_cmsr = null; 
                       String uriStr_e0sr = null; 
                       String uriStr_e1sr = null; 
                       String uriStr_e2sr = null; 
                       String uriStr_Slice = null; 
                       uriStr_Slice = Integer.toString(Module) +"/cc4/"+ Integer.toString(Slice) +"/cc4"+ Integer.toString(Slice);
                       uriStr_posr = uriStr_CCU4 + uriStr_Slice +"srs_posr"; 
                       StrTempCC4Reset = app.getResetValue(uriStr_posr);
                       StrTempCC4ActualX = app.getMuxValue(uriStr_posr);                
                       if(StrTempCC4Reset.compareTo(StrTempCC4ActualX) < 0) {
                          tempStr_posr = "WR_REG(CCU4"+ Integer.toString(Module) +"_CC4"+ Integer.toString(Slice) +"->SRS, CCU4_CC4_SRS_POSR_Msk, CCU4_CC4_SRS_POSR_Pos, CCU_SR" + StrTempCC4ActualX + ");"; 
                       } 
                       uriStr_cmsr = uriStr_CCU4 + uriStr_Slice +"srs_cmsr";
                       StrTempCC4Reset = app.getResetValue(uriStr_cmsr);
                       StrTempCC4ActualY = app.getMuxValue(uriStr_cmsr);                   
                       if (StrTempCC4Reset.compareTo(StrTempCC4ActualY) < 0) {
                          tempStr_cmsr = "WR_REG(CCU4"+ Integer.toString(Module) +"_CC4"+ Integer.toString(Slice) +"->SRS, CCU4_CC4_SRS_CMSR_Msk, CCU4_CC4_SRS_CMSR_Pos, CCU_SR" + StrTempCC4ActualY + ");"; 
                       } 
                       uriStr_e0sr = uriStr_CCU4 + uriStr_Slice +"srs_e0sr";
                       StrTempCC4Reset = app.getResetValue(uriStr_e0sr);
                       StrTempCC4Actual_e0sr = app.getMuxValue(uriStr_e0sr);                   
                       if (StrTempCC4Reset.compareTo(StrTempCC4Actual_e0sr) < 0) {
                          tempStr_e0sr = "WR_REG(CCU4"+ Integer.toString(Module) +"_CC4"+ Integer.toString(Slice) +"->SRS, CCU4_CC4_SRS_E0SR_Msk, CCU4_CC4_SRS_E0SR_Pos, CCU_SR" + StrTempCC4Actual_e0sr + ");"; 
                       } 
                       uriStr_e1sr = uriStr_CCU4 + uriStr_Slice +"srs_e1sr"; 
                       StrTempCC4Reset = app.getResetValue(uriStr_e1sr);
                       StrTempCC4Actual_e1sr = app.getMuxValue(uriStr_e1sr);                   
                       if (StrTempCC4Reset.compareTo(StrTempCC4Actual_e1sr) < 0) {
                         tempStr_e1sr = "WR_REG(CCU4"+ Integer.toString(Module) +"_CC4"+ Integer.toString(Slice) +"->SRS, CCU4_CC4_SRS_E1SR_Msk, CCU4_CC4_SRS_E1SR_Pos, CCU_SR" + StrTempCC4Actual_e1sr + ");"; 
                       } 
                       uriStr_e2sr = uriStr_CCU4 + uriStr_Slice +"srs_e2sr";
                       StrTempCC4Reset = app.getResetValue(uriStr_e2sr);
                       StrTempCC4Actual_e2sr = app.getMuxValue(uriStr_e2sr);                    
                       if (StrTempCC4Reset.compareTo(StrTempCC4Actual_e2sr) < 0) {
                         tempStr_e2sr = "WR_REG(CCU4"+ Integer.toString(Module) +"_CC4"+ Integer.toString(Slice) +"->SRS, CCU4_CC4_SRS_E2SR_Msk, CCU4_CC4_SRS_E2SR_Pos, CCU_SR" + StrTempCC4Actual_e2sr + ");"; 
                       } 
                       if((tempStr_posr != null)|(tempStr_cmsr != null)|(tempStr_e0sr != null)|(tempStr_e1sr != null)|(tempStr_e2sr != null) ){
    stringBuffer.append(TEXT_18);
    stringBuffer.append(Module);
    stringBuffer.append(TEXT_19);
    stringBuffer.append(Slice);
    stringBuffer.append(TEXT_20);
     if(tempStr_posr != null){
    stringBuffer.append(TEXT_21);
    stringBuffer.append(TEXT_22);
    stringBuffer.append( tempStr_posr);
    stringBuffer.append(TEXT_23);
     } 
                           if(tempStr_cmsr != null){
    stringBuffer.append(TEXT_24);
    stringBuffer.append(TEXT_25);
    stringBuffer.append( tempStr_cmsr);
    stringBuffer.append(TEXT_26);
     } 
                           if(tempStr_e0sr != null){
    stringBuffer.append(TEXT_27);
    stringBuffer.append(TEXT_28);
    stringBuffer.append( tempStr_e0sr);
    stringBuffer.append(TEXT_29);
     }
                           if(tempStr_e1sr != null){
    stringBuffer.append(TEXT_30);
    stringBuffer.append(TEXT_31);
    stringBuffer.append( tempStr_e1sr);
    stringBuffer.append(TEXT_32);
     }
                           if(tempStr_e2sr != null){
    stringBuffer.append(TEXT_33);
    stringBuffer.append(TEXT_34);
    stringBuffer.append( tempStr_e2sr);
    stringBuffer.append(TEXT_35);
     }
                       } 
             } 
         }
     } 
       //********* Capture/Compare Unit 4 (CAPCOM4) CONFIGURATIONS ---  END ************************* 
       
     
    //********* Capture/Compare Unit 8 (CAPCOM8) CONFIGURATIONS BEGIN ************************* 
       if(MyTempPeriName.compareTo("peripheral/ccu8") == 0) {
          String uriStr_CCU8 = "peripheral/ccu8/"; 
    stringBuffer.append(TEXT_36);
     for (int Module = 0; Module < 3; Module++) { 
               String StrTempCC8Reset = null; 
               String StrTempCC8Actual = null; 
               String uriCC8StrTemp = null;        
               uriCC8StrTemp = uriStr_CCU8+ Module +"/global/gctrl_pcis";
               StrTempCC8Reset = app.getResetValue(uriCC8StrTemp);  StrTempCC8Actual = app.getMuxValue(uriCC8StrTemp);              
               if(StrTempCC8Reset.compareTo(StrTempCC8Actual) < 0) {
    stringBuffer.append(TEXT_37);
    stringBuffer.append(Module);
    stringBuffer.append(TEXT_38);
    stringBuffer.append(StrTempCC8Actual);
    stringBuffer.append(TEXT_39);
     } 
                 for (int Slice = 0; Slice < 4; Slice++) { 
                       String tempC8StrEv0is = null; String tempC8StrEv1is = null; String tempC8StrEv2s = null;                   
                       String StrTempCC8ActualEv0is = null; 
                       String StrTempCC8ActualEv1is = null; 
                       String StrTempCC8Actual_ev2s = null; 
                       String uriC8Str_Ev0is = null; String uriC8Str_Ev1is = null; String uriC8Str_ev2s = null;
                       String uriCC8Str_Slice = null; 
                       uriCC8Str_Slice = Integer.toString(Module) +"/cc8/"+ Integer.toString(Slice) +"/";
                       uriC8Str_Ev0is = uriStr_CCU8 + uriCC8Str_Slice +"ins_ev0is";                
                       StrTempCC8Reset = app.getResetValue(uriC8Str_Ev0is);
                       StrTempCC8ActualEv0is = app.getMuxValue(uriC8Str_Ev0is);                   
                       if(StrTempCC8Reset.compareTo(StrTempCC8ActualEv0is) < 0) {
                          tempC8StrEv0is = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->INS, CCU8_CC8_INS_EV0IS_Msk, CCU8_CC8_INS_EV0IS_Pos, CCU8xINy" +  (char)(Integer.parseInt(StrTempCC8ActualEv0is.trim()) + 65)  + ");"; 
                       } 
                       uriC8Str_Ev1is = uriStr_CCU8 + uriCC8Str_Slice +"ins_ev1is";
                       StrTempCC8Reset = app.getResetValue(uriC8Str_Ev1is); 
                       StrTempCC8ActualEv1is = app.getMuxValue(uriC8Str_Ev1is);                   
                       if (StrTempCC8Reset.compareTo(StrTempCC8ActualEv1is) < 0) {
                          tempC8StrEv1is = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->INS, CCU8_CC8_INS_EV1IS_Msk, CCU8_CC8_INS_EV1IS_Pos, CCU8xINy" + (char)(Integer.parseInt(StrTempCC8ActualEv1is.trim()) + 65) + ");"; 
                       }  
                       uriC8Str_ev2s = uriStr_CCU8 + uriCC8Str_Slice +"ins_ev2s";
                       StrTempCC8Reset = app.getResetValue(uriC8Str_ev2s);
                       StrTempCC8Actual_ev2s = app.getMuxValue(uriC8Str_ev2s);               
                       if (StrTempCC8Reset.compareTo(StrTempCC8Actual_ev2s) < 0) {
                         tempC8StrEv2s = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINy" + (char)(Integer.parseInt(StrTempCC8Actual_ev2s.trim()) + 65) + ");"; 
                       } 
                      if((tempC8StrEv0is != null) | (tempC8StrEv1is != null) | (tempC8StrEv2s != null) ){
    stringBuffer.append(TEXT_40);
    stringBuffer.append(Module);
    stringBuffer.append(TEXT_41);
    stringBuffer.append(Slice);
    stringBuffer.append(TEXT_42);
     if(tempC8StrEv0is != null){
    stringBuffer.append(TEXT_43);
    stringBuffer.append(TEXT_44);
    stringBuffer.append( tempC8StrEv0is);
    stringBuffer.append(TEXT_45);
     } 
                           if(tempC8StrEv1is != null){
    stringBuffer.append(TEXT_46);
    stringBuffer.append(TEXT_47);
    stringBuffer.append( tempC8StrEv1is);
    stringBuffer.append(TEXT_48);
     } 
                           if(tempC8StrEv2s != null){
    stringBuffer.append(TEXT_49);
    stringBuffer.append(TEXT_50);
    stringBuffer.append( tempC8StrEv2s);
    stringBuffer.append(TEXT_51);
     }  
                        }  
                    }             
                 for (int Slice = 0; Slice < 4; Slice++) { 
                       String tempStr_posr = null;                    
                       String tempStr_cm1sr = null;                    
                       String tempStr_cm2sr = null;                    
                       String tempStr_e0sr = null;                    
                       String tempStr_e1sr = null;                    
                       String tempStr_e2sr = null;                    
                       String StrTempCC8Actual_posr = null; 
                       String StrTempCC8Actual_cm1sr = null; 
                       String StrTempCC8Actual_cm2sr = null; 
                       String StrTempCC8Actual_e0sr = null; 
                       String StrTempCC8Actual_e1sr = null; 
                       String StrTempCC8Actual_e2sr = null; 
                       String uriStr_posr = null; 
                       String uriStr_cm1sr = null; 
                       String uriStr_cm2sr = null; 
                       String uriStr_e0sr = null; 
                       String uriStr_e1sr = null; 
                       String uriStr_e2sr = null; 
                       String uriCC8Str_Slice = null; 
                       uriCC8Str_Slice = Integer.toString(Module) +"/cc8/"+ Integer.toString(Slice) +"/";
                       uriStr_posr = uriStr_CCU8 + uriCC8Str_Slice +"srs_posr"; 
                       StrTempCC8Reset = app.getResetValue(uriStr_posr);
                       StrTempCC8Actual_posr = app.getMuxValue(uriStr_posr);                
                       if(StrTempCC8Reset.compareTo(StrTempCC8Actual_posr) < 0) {
                          tempStr_posr = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->SRS, CCU8_CC8_SRS_POSR_Msk, CCU8_CC8_SRS_POSR_Pos, CCU_SR" + StrTempCC8Actual_posr + ");"; 
                       } 
                       uriStr_cm1sr = uriStr_CCU8 + uriCC8Str_Slice +"srs_cm1sr";
                       StrTempCC8Reset = app.getResetValue(uriStr_cm1sr);
                       StrTempCC8Actual_cm1sr = app.getMuxValue(uriStr_cm1sr);                   
                       if (StrTempCC8Reset.compareTo(StrTempCC8Actual_cm1sr) < 0) {
                          tempStr_cm1sr = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->SRS, CCU8_CC8_SRS_CM1SR_Msk, CCU8_CC8_SRS_CM1SR_Pos, CCU_SR" + StrTempCC8Actual_cm1sr + ");"; 
                       } 
                       uriStr_cm2sr = uriStr_CCU8 + uriCC8Str_Slice +"srs_cm2sr";
                       StrTempCC8Reset = app.getResetValue(uriStr_cm2sr);
                       StrTempCC8Actual_cm2sr = app.getMuxValue(uriStr_cm2sr);                   
                       if (StrTempCC8Reset.compareTo(StrTempCC8Actual_cm2sr) < 0) {
                          tempStr_cm2sr = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->SRS, CCU8_CC8_SRS_CM2SR_Msk, CCU8_CC8_SRS_CM2SR_Pos, CCU_SR" + StrTempCC8Actual_cm2sr + ");"; 
                       } 
                       uriStr_e0sr = uriStr_CCU8 + uriCC8Str_Slice +"srs_e0sr";
                       StrTempCC8Reset = app.getResetValue(uriStr_e0sr);
                       StrTempCC8Actual_e0sr = app.getMuxValue(uriStr_e0sr);                   
                       if (StrTempCC8Reset.compareTo(StrTempCC8Actual_e0sr) < 0) {
                          tempStr_e0sr = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->SRS, CCU8_CC8_SRS_E0SR_Msk, CCU8_CC8_SRS_E0SR_Pos, CCU_SR" + StrTempCC8Actual_e0sr + ");"; 
                       } 
                       uriStr_e1sr = uriStr_CCU8 + uriCC8Str_Slice +"srs_e1sr"; 
                       StrTempCC8Reset = app.getResetValue(uriStr_e1sr);
                       StrTempCC8Actual_e1sr = app.getMuxValue(uriStr_e1sr);                   
                       if (StrTempCC8Reset.compareTo(StrTempCC8Actual_e1sr) < 0) {
                         tempStr_e1sr = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->SRS, CCU8_CC8_SRS_E1SR_Msk, CCU8_CC8_SRS_E1SR_Pos, CCU_SR" + StrTempCC8Actual_e1sr + ");"; 
                       } 
                       uriStr_e2sr = uriStr_CCU8 + uriCC8Str_Slice +"srs_e2sr";
                       StrTempCC8Reset = app.getResetValue(uriStr_e2sr);
                       StrTempCC8Actual_e2sr = app.getMuxValue(uriStr_e2sr);                    
                       if (StrTempCC8Reset.compareTo(StrTempCC8Actual_e2sr) < 0) {
                         tempStr_e2sr = "WR_REG(CCU8"+ Integer.toString(Module) +"_CC8"+ Integer.toString(Slice) +"->SRS, CCU8_CC8_SRS_E2SR_Msk, CCU8_CC8_SRS_E2SR_Pos, CCU_SR" + StrTempCC8Actual_e2sr + ");"; 
                       } 
                       if((tempStr_posr != null)|(tempStr_cm1sr != null)|(tempStr_cm2sr != null)|(tempStr_e0sr != null)|(tempStr_e1sr != null)|(tempStr_e2sr != null) ){
    stringBuffer.append(TEXT_52);
    stringBuffer.append(Module);
    stringBuffer.append(TEXT_53);
    stringBuffer.append(Slice);
    stringBuffer.append(TEXT_54);
     if(tempStr_posr != null){
    stringBuffer.append(TEXT_55);
    stringBuffer.append(TEXT_56);
    stringBuffer.append( tempStr_posr);
    stringBuffer.append(TEXT_57);
     } 
                           if(tempStr_cm1sr != null){
    stringBuffer.append(TEXT_58);
    stringBuffer.append(TEXT_59);
    stringBuffer.append( tempStr_cm1sr);
    stringBuffer.append(TEXT_60);
     } 
                           if(tempStr_cm2sr != null){
    stringBuffer.append(TEXT_61);
    stringBuffer.append(TEXT_62);
    stringBuffer.append( tempStr_cm2sr);
    stringBuffer.append(TEXT_63);
     } 
                           if(tempStr_e0sr != null){
    stringBuffer.append(TEXT_64);
    stringBuffer.append(TEXT_65);
    stringBuffer.append( tempStr_e0sr);
    stringBuffer.append(TEXT_66);
     }
                           if(tempStr_e1sr != null){
    stringBuffer.append(TEXT_67);
    stringBuffer.append(TEXT_68);
    stringBuffer.append( tempStr_e1sr);
    stringBuffer.append(TEXT_69);
     }
                           if(tempStr_e2sr != null){
    stringBuffer.append(TEXT_70);
    stringBuffer.append(TEXT_71);
    stringBuffer.append( tempStr_e2sr);
    stringBuffer.append(TEXT_72);
     }
                       } 
              } 
         }  
     } 
     //-- END OF Capture/Compare Unit 8 (CAPCOM8) CONFIGURATIONS -- 
     
     
      //********* Ethernet MAC CONFIGURATIONS BEGIN ************************* 
      if(MyTempPeriName.compareTo("peripheral/eth") == 0) {
       String uriStr_ETH = "peripheral/eth/0/eth/"; 
    stringBuffer.append(TEXT_73);
     String StrResetETH = null;
                   String StrETHcon_rxd0 = null; String ActETHcon_rxd0 = null; String uriETHcon_rxd0 = null; 
                   String StrETHcon_rxd1 = null; String ActETHcon_rxd1 = null; String uriETHcon_rxd1 = null; 
                   String StrETHcon_rxd2 = null; String ActETHcon_rxd2 = null; String uriETHcon_rxd2 = null; 
                   String StrETHcon_rxd3 = null; String ActETHcon_rxd3 = null; String uriETHcon_rxd3 = null; 
                   String StrETHcon_rmii = null; String ActETHcon_rmii = null; String uriETHcon_rmii = null; 
                   String StrETHcon_crs_dv = null; String ActETHcon_crs_dv = null; String uriETHcon_crs_dv = null; 
                   String StrETHcon_crs = null; String ActETHcon_crs = null; String uriETHcon_crs = null; 
                   String StrETHcon_rxer = null; String ActETHcon_rxer = null; String uriETHcon_rxer = null; 
                   String StrETHcon_col = null; String ActETHcon_col = null; String uriETHcon_col = null; 
                   String StrETHcon_clk_tx = null; String ActETHcon_clk_tx = null; String uriETHcon_clk_tx = null; 
                   String StrETHcon_mdio = null; String ActETHcon_mdio = null; String uriETHcon_mdio = null; 
                   String StrETHcon_infsel = null; String ActETHcon_infsel = null; String uriETHcon_infsel = null;                    

                      uriETHcon_rxd0 = uriStr_ETH +"con_rxd0";
                      StrResetETH = app.getResetValue(uriETHcon_rxd0);
                   ActETHcon_rxd0 = app.getMuxValue(uriETHcon_rxd0);                   
                    if(StrResetETH.compareTo(ActETHcon_rxd0) < 0) 
                    {
                      StrETHcon_rxd0 = "WR_REG(ETH0_CON->CON, ETH_CON_RXD0_Msk, ETH_CON_RXD0_Pos, ETH_RXDx" + (char)(Integer.parseInt(ActETHcon_rxd0.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_rxd1 = uriStr_ETH +"con_rxd1";
                      StrResetETH = app.getResetValue(uriETHcon_rxd1);
                   ActETHcon_rxd1 = app.getMuxValue(uriETHcon_rxd1);                   
                    if(StrResetETH.compareTo(ActETHcon_rxd1) < 0) 
                    {
                      StrETHcon_rxd1 = "WR_REG(ETH0_CON->CON, ETH_CON_RXD1_Msk, ETH_CON_RXD1_Pos, ETH_RXDx" + (char)(Integer.parseInt(ActETHcon_rxd1.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_rxd2 = uriStr_ETH +"con_rxd2";
                      StrResetETH = app.getResetValue(uriETHcon_rxd2);
                   ActETHcon_rxd2 = app.getMuxValue(uriETHcon_rxd2);                   
                    if(StrResetETH.compareTo(ActETHcon_rxd2) < 0) 
                    {
                      StrETHcon_rxd2 = "WR_REG(ETH0_CON->CON, ETH_CON_RXD2_Msk, ETH_CON_RXD2_Pos, ETH_RXDx" + (char)(Integer.parseInt(ActETHcon_rxd2.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_rxd3 = uriStr_ETH +"con_rxd3";
                      StrResetETH = app.getResetValue(uriETHcon_rxd3);
                   ActETHcon_rxd3 = app.getMuxValue(uriETHcon_rxd3);                   
                    if(StrResetETH.compareTo(ActETHcon_rxd3) < 0) 
                    {
                      StrETHcon_rxd3 = "WR_REG(ETH0_CON->CON, ETH_CON_RXD3_Msk, ETH_CON_RXD3_Pos, ETH_RXDx" + (char)(Integer.parseInt(ActETHcon_rxd3.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_rmii = uriStr_ETH +"con_rmii";
                      StrResetETH = app.getResetValue(uriETHcon_rmii);
                   ActETHcon_rmii = app.getMuxValue(uriETHcon_rmii);                   
                    if(StrResetETH.compareTo(ActETHcon_rmii) < 0) 
                    {
                      StrETHcon_rmii = "WR_REG(ETH0_CON->CON, ETH_CON_CLK_RMII_Msk, ETH_CON_CLK_RMII_Pos, ETH_RMII" + (char)(Integer.parseInt(ActETHcon_rmii.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_crs_dv = uriStr_ETH +"con_crs_dv";
                      StrResetETH = app.getResetValue(uriETHcon_crs_dv);
                   ActETHcon_crs_dv = app.getMuxValue(uriETHcon_crs_dv);                   
                    if(StrResetETH.compareTo(ActETHcon_crs_dv) < 0) 
                    {
                      StrETHcon_crs_dv = "WR_REG(ETH0_CON->CON, ETH_CON_CRS_DV_Msk, ETH_CON_CRS_DV_Pos, ETH_CRS_DV" + (char)(Integer.parseInt(ActETHcon_crs_dv.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_crs = uriStr_ETH +"con_crs";
                      StrResetETH = app.getResetValue(uriETHcon_crs);
                   ActETHcon_crs = app.getMuxValue(uriETHcon_crs);                   
                    if(StrResetETH.compareTo(ActETHcon_crs) < 0) 
                    {
                      StrETHcon_crs = "WR_REG(ETH0_CON->CON, ETH_CON_CRS_Msk, ETH_CON_CRS_Pos, ETH_CRS" + (char)(Integer.parseInt(ActETHcon_crs.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_rxer = uriStr_ETH +"con_rxer";
                      StrResetETH = app.getResetValue(uriETHcon_rxer);
                   ActETHcon_rxer = app.getMuxValue(uriETHcon_rxer);                   
                    if(StrResetETH.compareTo(ActETHcon_rxer) < 0) 
                    {
                      StrETHcon_rxer = "WR_REG(ETH0_CON->CON, ETH_CON_RXER_Msk, ETH_CON_RXER_Pos, ETH_RXER" + (char)(Integer.parseInt(ActETHcon_rxer.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_col = uriStr_ETH +"con_col";
                      StrResetETH = app.getResetValue(uriETHcon_col);
                   ActETHcon_col = app.getMuxValue(uriETHcon_col);                   
                    if(StrResetETH.compareTo(ActETHcon_col) < 0) {
                      StrETHcon_col = "WR_REG(ETH0_CON->CON, ETH_CON_COL_Msk, ETH_CON_COL_Pos, ETH_COL" + (char)(Integer.parseInt(ActETHcon_col.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_clk_tx = uriStr_ETH +"con_clk_tx";
                      StrResetETH = app.getResetValue(uriETHcon_clk_tx);
                   ActETHcon_clk_tx = app.getMuxValue(uriETHcon_clk_tx);                   
                    if(StrResetETH.compareTo(ActETHcon_clk_tx) < 0) 
                    {
                      StrETHcon_clk_tx = "WR_REG(ETH0_CON->CON, ETH_CON_CLK_TX_Msk, ETH_CON_CLK_TX_Pos, ETH_CLK_TX" + (char)(Integer.parseInt(ActETHcon_clk_tx.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_mdio = uriStr_ETH +"con_mdio";
                      StrResetETH = app.getResetValue(uriETHcon_mdio);
                   ActETHcon_mdio = app.getMuxValue(uriETHcon_mdio);                   
                    if(StrResetETH.compareTo(ActETHcon_mdio) < 0) 
                    {
                      StrETHcon_mdio = "WR_REG(ETH0_CON->CON, ETH_CON_MDIO_Msk, ETH_CON_MDIO_Pos, ETH_MDIO" + (char)(Integer.parseInt(ActETHcon_mdio.trim()) + 65) + ");"; 
                      } 
                      uriETHcon_infsel = uriStr_ETH +"con_infsel";
                      StrResetETH = app.getResetValue(uriETHcon_infsel);
                   ActETHcon_infsel = app.getMuxValue(uriETHcon_infsel);                   
                    if(StrResetETH.compareTo(ActETHcon_infsel) < 0) 
                    {
                      StrETHcon_infsel = "WR_REG(ETH0_CON->CON, ETH_CON_INFSEL_Msk, ETH_CON_INFSEL_Pos," + ActETHcon_infsel + ");"; 
                      }                       
                    if((StrETHcon_rxd0 != null)|(StrETHcon_rxd1 != null)|(StrETHcon_rxd2 != null)|(StrETHcon_rxd3 != null)
                     |(StrETHcon_rmii != null)|(StrETHcon_crs_dv != null)|(StrETHcon_crs != null)|(StrETHcon_rxer != null)
                     |(StrETHcon_col != null)|(StrETHcon_clk_tx != null)|(StrETHcon_mdio != null)|(StrETHcon_infsel != null)){
    stringBuffer.append(TEXT_74);
     if(StrETHcon_rxd0 != null){
    stringBuffer.append(TEXT_75);
    stringBuffer.append(TEXT_76);
    stringBuffer.append( StrETHcon_rxd0);
    stringBuffer.append(TEXT_77);
     } if(StrETHcon_rxd1 != null){
    stringBuffer.append(TEXT_78);
    stringBuffer.append(TEXT_79);
    stringBuffer.append( StrETHcon_rxd1);
    stringBuffer.append(TEXT_80);
     } if(StrETHcon_rxd2 != null){
    stringBuffer.append(TEXT_81);
    stringBuffer.append(TEXT_82);
    stringBuffer.append( StrETHcon_rxd2);
    stringBuffer.append(TEXT_83);
     } if(StrETHcon_rxd3 != null){
    stringBuffer.append(TEXT_84);
    stringBuffer.append(TEXT_85);
    stringBuffer.append( StrETHcon_rxd3);
    stringBuffer.append(TEXT_86);
     } if(StrETHcon_rmii != null){
    stringBuffer.append(TEXT_87);
    stringBuffer.append(TEXT_88);
    stringBuffer.append( StrETHcon_rmii);
    stringBuffer.append(TEXT_89);
     } if(StrETHcon_crs_dv != null){
    stringBuffer.append(TEXT_90);
    stringBuffer.append(TEXT_91);
    stringBuffer.append( StrETHcon_crs_dv);
    stringBuffer.append(TEXT_92);
     } if(StrETHcon_crs != null){
    stringBuffer.append(TEXT_93);
    stringBuffer.append(TEXT_94);
    stringBuffer.append( StrETHcon_crs);
    stringBuffer.append(TEXT_95);
     } if(StrETHcon_rxer != null){
    stringBuffer.append(TEXT_96);
    stringBuffer.append(TEXT_97);
    stringBuffer.append( StrETHcon_rxer);
    stringBuffer.append(TEXT_98);
     } if(StrETHcon_col != null){
    stringBuffer.append(TEXT_99);
    stringBuffer.append(TEXT_100);
    stringBuffer.append( StrETHcon_col);
    stringBuffer.append(TEXT_101);
     } if(StrETHcon_clk_tx != null){
    stringBuffer.append(TEXT_102);
    stringBuffer.append(TEXT_103);
    stringBuffer.append( StrETHcon_clk_tx);
    stringBuffer.append(TEXT_104);
     } if(StrETHcon_mdio != null){
    stringBuffer.append(TEXT_105);
    stringBuffer.append(TEXT_106);
    stringBuffer.append( StrETHcon_mdio);
    stringBuffer.append(TEXT_107);
     } if(StrETHcon_infsel != null){
    stringBuffer.append(TEXT_108);
    stringBuffer.append(TEXT_109);
    stringBuffer.append( StrETHcon_infsel);
    stringBuffer.append(TEXT_110);
     } 
                   }                   
      } 
      //********* Ethernet MAC CONFIGURATIONS ---  END ************************* 
      
           
     //********* Delta-Sigma Demodulator (DSD) --- BEGIN ************************* 
     if(MyTempPeriName.compareTo("peripheral/dsd") == 0) {
         String uriStr_DSD = "peripheral/dsd/0/Channel/"; 
        //********* Delta-Sigma Demodulator (DSD) CONFIGURATIONS ************************* 
         for (int Ch = 0; Ch < 4; Ch++) { 
               String uriStr_xReg = null; 
			   String StrTempDSDReset = null;
			   String StrTempDSDActualX = null;
			   String temp_dicfg_dsrc = null;
			   String temp_dicfg_dsrc_sel = null;
			   String temp_dicfg_csrc = null;
			   String temp_dicfg_scwc = null;
			   String temp_dicfg_trsel = null;
			   String temp_dicfg_trwc = null;
			   String temp_DIN = null;			   
               uriStr_xReg = uriStr_DSD + Integer.toString(Ch) + "/dicfg_dsrcsel";
               StrTempDSDReset = app.getResetValue(uriStr_xReg);
               StrTempDSDActualX = app.getMuxValue(uriStr_xReg);                   
               if(StrTempDSDReset.compareTo(StrTempDSDActualX) < 0) { 
	              if(StrTempDSDActualX.equals("1")) {
	               	temp_DIN = "A";
               		}
	              else if(StrTempDSDActualX.equals("2")) {
	               	temp_DIN = "B";
	                }               
temp_dicfg_dsrc_sel = "WR_REG(DSD_CH"+ Integer.toString(Ch) +"->DICFG, DSD_CH_DICFG_DSWC_DSRCSEL_Msk, DSD_CH_DICFG_DSRC_Pos, \\\n     ((((DSD_CH"+ Integer.toString(Ch) +"->DICFG) & DSD_CH_DICFG_DSRC_Msk) | (DSD_CH_DICFG_DSWC_Msk | (DINx" + temp_DIN + ")<<1))));";
               } 
               uriStr_xReg = uriStr_DSD + Integer.toString(Ch) + "/dicfg_csrc";
               StrTempDSDReset = app.getResetValue(uriStr_xReg);
               StrTempDSDActualX = app.getMuxValue(uriStr_xReg);                   
               if(StrTempDSDReset.compareTo(StrTempDSDActualX) < 0) { 
	              if(StrTempDSDActualX.equals("1")) {
	               	temp_DIN = "A";
               		}
	              else if(StrTempDSDActualX.equals("2")) {
	               	temp_DIN = "B";
	                }               
	              else if(StrTempDSDActualX.equals("15")) {
	               	temp_DIN = "INTERNAL";
	                }       
temp_dicfg_csrc = "WR_REG(DSD_CH"+ Integer.toString(Ch) +"->DICFG, DSD_CH_DICFG_SCWC_STROBE_CSRC_Msk, DSD_CH_DICFG_CSRC_Pos, \\\n     (((((DSD_CH"+ Integer.toString(Ch) +"->DICFG) & DSD_CH_DICFG_STROBE_Msk) | DSD_CH_DICFG_SCWC_Msk) >> DSD_CH_DICFG_CSRC_Pos) | MCLKx" + temp_DIN + "));";               
               } 
               uriStr_xReg = uriStr_DSD + Integer.toString(Ch) + "/dicfg_trsel";
               StrTempDSDReset = app.getResetValue(uriStr_xReg);
               StrTempDSDActualX = app.getMuxValue(uriStr_xReg);                   
               if(StrTempDSDReset.compareTo(StrTempDSDActualX) < 0){ 
  temp_dicfg_trsel = "WR_REG(DSD_CH"+ Integer.toString(Ch) +"->DICFG, DSD_CH_DICFG_TRWC_TRSEL_Msk, DSD_CH_DICFG_ITRMODE_Pos, \\\n     ((((DSD_CH"+ Integer.toString(Ch) +"->DICFG) & (DSD_CH_DICFG_ITRMODE_Msk|DSD_CH_DICFG_TSTRMODE_Msk))| \\\n     (DSD_CH_DICFG_TRWC_Msk) | (ITRx" + (char)(Integer.parseInt(StrTempDSDActualX.trim()) + 65)  + "  << DSD_CH_DICFG_TRSEL_Pos)) >> DSD_CH_DICFG_ITRMODE_Pos));";

               } 
    stringBuffer.append(TEXT_111);
     if((temp_dicfg_dsrc_sel != null) | (temp_dicfg_csrc != null) | (temp_dicfg_trsel != null) ){
    stringBuffer.append(TEXT_112);
    stringBuffer.append(Ch);
     if(temp_dicfg_dsrc_sel != null){
    stringBuffer.append(TEXT_113);
    stringBuffer.append(TEXT_114);
    stringBuffer.append(temp_dicfg_dsrc_sel);
     } 
     if(temp_dicfg_csrc != null){
    stringBuffer.append(TEXT_115);
    stringBuffer.append( temp_dicfg_csrc);
    stringBuffer.append(TEXT_116);
     } 
     if(temp_dicfg_trsel != null){
    stringBuffer.append(TEXT_117);
    stringBuffer.append( temp_dicfg_trsel);
    stringBuffer.append(TEXT_118);
     } 
     } 
                 uriStr_xReg = uriStr_DSD + Integer.toString(Ch) + "/rectcfg_ssrc";
               StrTempDSDReset = app.getResetValue(uriStr_xReg);
               StrTempDSDActualX = app.getMuxValue(uriStr_xReg);                   
               if(StrTempDSDReset.compareTo(StrTempDSDActualX) < 0) { 
    stringBuffer.append(TEXT_119);
    stringBuffer.append(Ch);
    stringBuffer.append(TEXT_120);
    stringBuffer.append(Ch);
    stringBuffer.append(TEXT_121);
    stringBuffer.append(StrTempDSDActualX);
    stringBuffer.append(TEXT_122);
                  } 
         }             
     } 
       //********* Delta-Sigma Demodulator (DSD) CONFIGURATIONS ---  END ************************* 
       
    
     //********* Multi CAN CONFIGURATIONS --- BEGIN *************************
    if(MyTempPeriName.compareTo("peripheral/can") == 0) {
    stringBuffer.append(TEXT_123);
     String CANuri = null;
     String NODExTypedef = null; 
     String MOxTypedef = null; 
     String RstCANuriMuxVal = null; 
     String ActCANuriMuxVal = null; 
     for (int NodeNr=0; NodeNr<=2; NodeNr++) { 
     CANuri = "peripheral/can/0/node/" + NodeNr + "/npcr_rxsel"; 
     RstCANuriMuxVal = app.getResetValue(CANuri); 
    stringBuffer.append(TEXT_124);
     ActCANuriMuxVal = app.getMuxValue(CANuri); 
     if((ActCANuriMuxVal.compareTo(RstCANuriMuxVal) != 0) && (ActCANuriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_125);
     if (NODExTypedef != "Defined") { 
    stringBuffer.append(TEXT_126);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_127);
     NODExTypedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_128);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_129);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_130);
    stringBuffer.append( app.getMuxValue(CANuri) );
    stringBuffer.append(TEXT_131);
     } 
     CANuri = "peripheral/can/0/node/" + NodeNr + "/nipr_trinp"; 
     RstCANuriMuxVal = app.getResetValue(CANuri); 
    stringBuffer.append(TEXT_132);
     ActCANuriMuxVal = app.getMuxValue(CANuri); 
     if((ActCANuriMuxVal.compareTo(RstCANuriMuxVal) != 0) && (ActCANuriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_133);
     if (NODExTypedef != "Defined") { 
    stringBuffer.append(TEXT_134);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_135);
     NODExTypedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_136);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_137);
    stringBuffer.append( app.getMuxValue(CANuri) );
    stringBuffer.append(TEXT_138);
     } 
     CANuri = "peripheral/can/0/node/" + NodeNr + "/nipr_lecinp"; 
     RstCANuriMuxVal = app.getResetValue(CANuri); 
    stringBuffer.append(TEXT_139);
     ActCANuriMuxVal = app.getMuxValue(CANuri); 
     if((ActCANuriMuxVal.compareTo(RstCANuriMuxVal) != 0) && (ActCANuriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_140);
     if (NODExTypedef != "Defined") { 
    stringBuffer.append(TEXT_141);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_142);
     NODExTypedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_143);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_144);
    stringBuffer.append( app.getMuxValue(CANuri) );
    stringBuffer.append(TEXT_145);
     } 
     CANuri = "peripheral/can/0/node/" + NodeNr + "/nipr_alinp"; 
     RstCANuriMuxVal = app.getResetValue(CANuri); 
    stringBuffer.append(TEXT_146);
     ActCANuriMuxVal = app.getMuxValue(CANuri); 
     if((ActCANuriMuxVal.compareTo(RstCANuriMuxVal) != 0) && (ActCANuriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_147);
     if (NODExTypedef != "Defined") { 
    stringBuffer.append(TEXT_148);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_149);
     NODExTypedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_150);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_151);
    stringBuffer.append( app.getMuxValue(CANuri) );
    stringBuffer.append(TEXT_152);
     } 
     CANuri = "peripheral/can/0/node/" + NodeNr + "/nipr_cfcinp"; 
     RstCANuriMuxVal = app.getResetValue(CANuri); 
    stringBuffer.append(TEXT_153);
     ActCANuriMuxVal = app.getMuxValue(CANuri); 
     if((ActCANuriMuxVal.compareTo(RstCANuriMuxVal) != 0) && (ActCANuriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_154);
     if (NODExTypedef != "Defined") { 
    stringBuffer.append(TEXT_155);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_156);
     NODExTypedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_157);
    stringBuffer.append( NodeNr);
    stringBuffer.append(TEXT_158);
    stringBuffer.append( app.getMuxValue(CANuri) );
    stringBuffer.append(TEXT_159);
     } 
     NODExTypedef = null; 
     } 
     for (int MONr=0; MONr<=63; MONr++) { 
     CANuri = "peripheral/can/0/mo/" + MONr + "/moipr_txinp"; 
     RstCANuriMuxVal = app.getResetValue(CANuri); 
    stringBuffer.append(TEXT_160);
     ActCANuriMuxVal = app.getMuxValue(CANuri); 
     if((ActCANuriMuxVal.compareTo(RstCANuriMuxVal) != 0) && (ActCANuriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_161);
     if (MOxTypedef != "Defined") { 
    stringBuffer.append(TEXT_162);
    stringBuffer.append( MONr);
    stringBuffer.append(TEXT_163);
     MOxTypedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_164);
    stringBuffer.append( MONr);
    stringBuffer.append(TEXT_165);
    stringBuffer.append( app.getMuxValue(CANuri) );
    stringBuffer.append(TEXT_166);
     } 
     CANuri = "peripheral/can/0/mo/" + MONr + "/moipr_rxinp"; 
     RstCANuriMuxVal = app.getResetValue(CANuri); 
    stringBuffer.append(TEXT_167);
     ActCANuriMuxVal = app.getMuxValue(CANuri); 
     if((ActCANuriMuxVal.compareTo(RstCANuriMuxVal) != 0) && (ActCANuriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_168);
     if (MOxTypedef != "Defined") { 
    stringBuffer.append(TEXT_169);
    stringBuffer.append( MONr);
    stringBuffer.append(TEXT_170);
     MOxTypedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_171);
    stringBuffer.append( MONr);
    stringBuffer.append(TEXT_172);
    stringBuffer.append( app.getMuxValue(CANuri) );
    stringBuffer.append(TEXT_173);
     } 
     MOxTypedef = null; 
     } 
     } 
     //********* Multi CAN CONFIGURATIONS ---  END ************************* 
     //********* POSIF CONFIGURATIONS --- BEGIN ************************* 
    if(MyTempPeriName.compareTo("peripheral/posif") == 0) {
    stringBuffer.append(TEXT_174);
     String POSIF0uri = null;
     String POSIF0Typedef = null; 
     String RstPOSIF0uriMuxVal = null; 
     String ActPOSIF0uriMuxVal = null; 
     POSIF0uri = "peripheral/Posif/0/Posif/pconf_insel0"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_175);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_176);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_177);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_178);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_179);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pconf_insel1"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_180);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_181);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_182);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_183);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_184);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pconf_insel2"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_185);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_186);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_187);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_188);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_189);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pconf_dsel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_190);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_191);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_192);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_193);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_194);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pconf_ewis"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_195);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_196);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_197);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_198);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_199);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pconf_msets"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_200);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_201);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_202);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_203);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_204);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pconf_msyns"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_205);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_206);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_207);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_208);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_209);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_eche"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_210);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_211);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_212);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_213);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_214);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_chesel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_215);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_216);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_217);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_218);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_219);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_ewhe"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_220);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_221);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_222);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_223);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_224);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_whesel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_225);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_226);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_227);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_228);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_229);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_ehie"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_230);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_231);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_232);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_233);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_234);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_hiesel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_235);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_236);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_237);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_238);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_239);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_emst"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_240);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_241);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_242);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_243);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_244);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_mstsel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_245);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_246);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_247);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_248);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_249);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_eindx"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_250);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_251);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_252);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_253);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_254);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_indsel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_255);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_256);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_257);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_258);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_259);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_eerr"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_260);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_261);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_262);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_263);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_264);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_errsel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_265);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_266);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_267);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_268);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_269);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_ecnt"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_270);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_271);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_272);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_273);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_274);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_cntsel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_275);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_276);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_277);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_278);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_279);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_edir"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_280);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_281);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_282);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_283);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_284);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_dirsel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_285);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_286);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_287);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_288);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_289);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_epclk"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_290);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_291);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_292);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_293);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_294);
     } 
     POSIF0uri = "peripheral/Posif/0/Posif/pflge_pclsel"; 
     RstPOSIF0uriMuxVal = app.getResetValue(POSIF0uri); 
    stringBuffer.append(TEXT_295);
     ActPOSIF0uriMuxVal = app.getMuxValue(POSIF0uri); 
     if((ActPOSIF0uriMuxVal.compareTo(RstPOSIF0uriMuxVal) != 0) && (ActPOSIF0uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_296);
     if (POSIF0Typedef != "Defined") { 
    stringBuffer.append(TEXT_297);
     POSIF0Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_298);
    stringBuffer.append( app.getMuxValue(POSIF0uri) );
    stringBuffer.append(TEXT_299);
     } 
     POSIF0Typedef = null; 
    stringBuffer.append(TEXT_300);
     String POSIF1uri = null;
     String POSIF1Typedef = null; 
     String RstPOSIF1uriMuxVal = null; 
     String ActPOSIF1uriMuxVal = null; 
     POSIF1uri = "peripheral/Posif/1/Posif/pconf_insel0"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_301);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_302);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_303);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_304);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_305);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pconf_insel1"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_306);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_307);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_308);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_309);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_310);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pconf_insel2"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_311);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_312);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_313);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_314);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_315);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pconf_dsel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_316);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_317);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_318);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_319);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_320);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pconf_ewis"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_321);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_322);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_323);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_324);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_325);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pconf_msets"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_326);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_327);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_328);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_329);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_330);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pconf_msyns"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_331);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_332);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_333);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_334);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_335);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_eche"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_336);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_337);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_338);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_339);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_340);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_chesel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_341);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_342);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_343);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_344);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_345);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_ewhe"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_346);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_347);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_348);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_349);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_350);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_whesel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_351);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_352);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_353);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_354);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_355);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_ehie"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_356);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_357);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_358);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_359);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_360);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_hiesel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_361);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_362);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_363);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_364);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_365);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_emst"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_366);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_367);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_368);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_369);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_370);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_mstsel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_371);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_372);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_373);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_374);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_375);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_eindx"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_376);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_377);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_378);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_379);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_380);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_indsel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_381);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_382);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_383);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_384);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_385);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_eerr"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_386);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_387);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_388);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_389);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_390);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_errsel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_391);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_392);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_393);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_394);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_395);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_ecnt"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_396);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_397);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_398);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_399);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_400);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_cntsel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_401);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_402);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_403);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_404);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_405);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_edir"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_406);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_407);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_408);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_409);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_410);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_dirsel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_411);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_412);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_413);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_414);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_415);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_epclk"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_416);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_417);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_418);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_419);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_420);
     } 
     POSIF1uri = "peripheral/Posif/1/Posif/pflge_pclsel"; 
     RstPOSIF1uriMuxVal = app.getResetValue(POSIF1uri); 
    stringBuffer.append(TEXT_421);
     ActPOSIF1uriMuxVal = app.getMuxValue(POSIF1uri); 
     if((ActPOSIF1uriMuxVal.compareTo(RstPOSIF1uriMuxVal) != 0) && (ActPOSIF1uriMuxVal.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_422);
     if (POSIF1Typedef != "Defined") { 
    stringBuffer.append(TEXT_423);
     POSIF1Typedef = "Defined"; 
     } 
    stringBuffer.append(TEXT_424);
    stringBuffer.append( app.getMuxValue(POSIF1uri) );
    stringBuffer.append(TEXT_425);
     } 
     POSIF1Typedef = null; 
     } 
     //********* POSIF CONFIGURATIONS ---  END ************************* 
     //********* MODULE USIC CONFIGURATIONS BEGIN ************************* 
    stringBuffer.append(TEXT_426);
    if(MyTempPeriName.compareTo("peripheral/usic") == 0) {
    stringBuffer.append(TEXT_427);
     int UsicNum = 3; 
   int UsicChannel = 2;
   String UsicBaseuri = "peripheral/usic/";
   String UsicSfruri = "";
     for (int k=0; k< UsicNum; k++) { 
     for (int l=0; l< UsicChannel; l++) { 
    stringBuffer.append(TEXT_428);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_429);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_430);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/dx0cr_dsel" ;	      
      String rstDX0CR_DSEL = app.getResetValue(UsicSfruri); 
      String actDX0CR_DSEL = app.getMuxValue(UsicSfruri); 
      if((actDX0CR_DSEL.compareTo(rstDX0CR_DSEL) != 0) && (actDX0CR_DSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_431);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_432);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_433);
    stringBuffer.append(actDX0CR_DSEL);
    stringBuffer.append(TEXT_434);
     } 
    stringBuffer.append(TEXT_435);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/dx1cr_dsel" ;  
     String rstDX1CR_DSEL = app.getResetValue(UsicSfruri); 
     String actDX1CR_DSEL = app.getMuxValue(UsicSfruri);         
     if((actDX1CR_DSEL.compareTo(rstDX1CR_DSEL) != 0) && (actDX1CR_DSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_436);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_437);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_438);
    stringBuffer.append(actDX1CR_DSEL);
    stringBuffer.append(TEXT_439);
     } 
    stringBuffer.append(TEXT_440);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/dx2cr_dsel" ;  
     String rstDX2CR_DSEL = app.getResetValue(UsicSfruri); 
     String actDX2CR_DSEL = app.getMuxValue(UsicSfruri);                
     if((actDX2CR_DSEL.compareTo(rstDX2CR_DSEL) != 0) && (actDX2CR_DSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_441);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_442);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_443);
    stringBuffer.append(actDX2CR_DSEL);
    stringBuffer.append(TEXT_444);
     } 
    stringBuffer.append(TEXT_445);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/dx3cr_dsel" ;  
     String rstDX3CR_DSEL = app.getResetValue(UsicSfruri); 
     String actDX3CR_DSEL = app.getMuxValue(UsicSfruri);                
     if((actDX3CR_DSEL.compareTo(rstDX3CR_DSEL) != 0) && (actDX3CR_DSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_446);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_447);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_448);
    stringBuffer.append(actDX3CR_DSEL);
    stringBuffer.append(TEXT_449);
     } 
    stringBuffer.append(TEXT_450);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/dx4cr_dsel" ;  
     String rstDX4CR_DSEL = app.getResetValue(UsicSfruri); 
     String actDX4CR_DSEL = app.getMuxValue(UsicSfruri);               
     if((actDX4CR_DSEL.compareTo(rstDX4CR_DSEL) != 0) && (actDX4CR_DSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_451);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_452);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_453);
    stringBuffer.append(actDX4CR_DSEL);
    stringBuffer.append(TEXT_454);
     } 
    stringBuffer.append(TEXT_455);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/dx5cr_dsel" ; 
     String rstDX5CR_DSEL = app.getResetValue(UsicSfruri); 
     String actDX5CR_DSEL = app.getMuxValue(UsicSfruri);                
     if((actDX5CR_DSEL.compareTo(rstDX5CR_DSEL) != 0) && (actDX5CR_DSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_456);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_457);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_458);
    stringBuffer.append(actDX5CR_DSEL);
    stringBuffer.append(TEXT_459);
     } 
    stringBuffer.append(TEXT_460);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/ccr_hpcen" ; 
     String rstCCR_HPCEN = app.getResetValue(UsicSfruri);
     String actCCR_HPCEN = app.getMuxValue(UsicSfruri);               
     if((actCCR_HPCEN.compareTo(rstCCR_HPCEN) != 0) && (actCCR_HPCEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_461);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_462);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_463);
    stringBuffer.append(actCCR_HPCEN);
    stringBuffer.append(TEXT_464);
     } 
    stringBuffer.append(TEXT_465);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/ccr_tsien" ; 
    String rstCCR_TSIEN = app.getResetValue(UsicSfruri);
    String actCCR_TSIEN = app.getMuxValue(UsicSfruri);               
    if((actCCR_TSIEN.compareTo(rstCCR_TSIEN) != 0) && (actCCR_TSIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_466);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_467);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_468);
    stringBuffer.append(actCCR_TSIEN);
    stringBuffer.append(TEXT_469);
     } 
    stringBuffer.append(TEXT_470);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/ccr_tbien" ; 
    String rstCCR_TBIEN = app.getResetValue(UsicSfruri); 
    String actCCR_TBIEN = app.getMuxValue(UsicSfruri);              
    if((actCCR_TBIEN.compareTo(rstCCR_TBIEN) != 0) && (actCCR_TBIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_471);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_472);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_473);
    stringBuffer.append(actCCR_TBIEN);
    stringBuffer.append(TEXT_474);
     } 
    stringBuffer.append(TEXT_475);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/ccr_rsien" ; 
    String rstCCR_RSIEN = app.getResetValue(UsicSfruri); 
    String actCCR_RSIEN = app.getMuxValue(UsicSfruri);                
    if((actCCR_RSIEN.compareTo(rstCCR_RSIEN) != 0) && (actCCR_RSIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_476);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_477);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_478);
    stringBuffer.append(actCCR_RSIEN);
    stringBuffer.append(TEXT_479);
     } 
    stringBuffer.append(TEXT_480);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/ccr_rien" ;  
   String rstCCR_RIEN = app.getResetValue(UsicSfruri);  
   String actCCR_RIEN = app.getMuxValue(UsicSfruri);               
   if((actCCR_RIEN.compareTo(rstCCR_RIEN) != 0) && (actCCR_RIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_481);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_482);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_483);
    stringBuffer.append(actCCR_RIEN);
    stringBuffer.append(TEXT_484);
     } 
    stringBuffer.append(TEXT_485);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/ccr_aien" ;  
   String rstCCR_AIEN = app.getResetValue(UsicSfruri);  
   String actCCR_AIEN = app.getMuxValue(UsicSfruri);              
  if((actCCR_AIEN.compareTo(rstCCR_AIEN) != 0) && (actCCR_AIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_486);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_487);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_488);
    stringBuffer.append(actCCR_AIEN);
    stringBuffer.append(TEXT_489);
     } 
    stringBuffer.append(TEXT_490);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/ccr_dlien" ; 
   String rstCCR_DLIEN = app.getResetValue(UsicSfruri); 
   String actCCR_DLIEN = app.getMuxValue(UsicSfruri);                
   if((actCCR_DLIEN.compareTo(rstCCR_DLIEN) != 0) && (actCCR_DLIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_491);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_492);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_493);
    stringBuffer.append(actCCR_DLIEN);
    stringBuffer.append(TEXT_494);
     } 
    stringBuffer.append(TEXT_495);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/ccr_brgien" ;  
   String rstCCR_BRGIEN = app.getResetValue(UsicSfruri); 
   String actCCR_BRGIEN = app.getMuxValue(UsicSfruri);               
  if((actCCR_BRGIEN.compareTo(rstCCR_BRGIEN) != 0) && (actCCR_BRGIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_496);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_497);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_498);
    stringBuffer.append(actCCR_BRGIEN);
    stringBuffer.append(TEXT_499);
     } 
    stringBuffer.append(TEXT_500);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/tbctr_stbien" ;  
   String rstTBCTR_STBIEN = app.getResetValue(UsicSfruri); 
   String actTBCTR_STBIEN = app.getMuxValue(UsicSfruri);               
   if((actTBCTR_STBIEN.compareTo(rstTBCTR_STBIEN) != 0) && (actTBCTR_STBIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_501);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_502);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_503);
    stringBuffer.append(actTBCTR_STBIEN);
    stringBuffer.append(TEXT_504);
     } 
    stringBuffer.append(TEXT_505);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/tbctr_tberien" ;  
   String rstTBCTR_TBERIEN = app.getResetValue(UsicSfruri);  
   String actTBCTR_TBERIEN = app.getMuxValue(UsicSfruri);               
  if((actTBCTR_TBERIEN.compareTo(rstTBCTR_TBERIEN) != 0) && (actTBCTR_TBERIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_506);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_507);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_508);
    stringBuffer.append(actTBCTR_TBERIEN);
    stringBuffer.append(TEXT_509);
     } 
    stringBuffer.append(TEXT_510);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/rbctr_srbien" ; 
   String rstRBCTR_SRBIEN = app.getResetValue(UsicSfruri);  
   String actRBCTR_SRBIEN = app.getMuxValue(UsicSfruri);               
   if((actRBCTR_SRBIEN.compareTo(rstRBCTR_SRBIEN) != 0) && (actRBCTR_SRBIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_511);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_512);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_513);
    stringBuffer.append(actRBCTR_SRBIEN);
    stringBuffer.append(TEXT_514);
     } 
    stringBuffer.append(TEXT_515);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/rbctr_rberien" ;  
   String rstRBCTR_RBERIEN = app.getResetValue(UsicSfruri); 
   String actRBCTR_RBERIEN = app.getMuxValue(UsicSfruri);                
  if((actRBCTR_RBERIEN.compareTo(rstRBCTR_RBERIEN) != 0) && (actRBCTR_RBERIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_516);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_517);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_518);
    stringBuffer.append(actRBCTR_RBERIEN);
    stringBuffer.append(TEXT_519);
     } 
    stringBuffer.append(TEXT_520);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/rbctr_arbien" ; 
   String rstRBCTR_ARBIEN = app.getResetValue(UsicSfruri);  
   String actRBCTR_ARBIEN = app.getMuxValue(UsicSfruri);               
   if((actRBCTR_ARBIEN.compareTo(rstRBCTR_ARBIEN) != 0) && (actRBCTR_ARBIEN.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_521);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_522);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_523);
    stringBuffer.append(actRBCTR_ARBIEN);
    stringBuffer.append(TEXT_524);
     } 
    stringBuffer.append(TEXT_525);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/inpr_tsinp" ;  
   String rstINPR_TSINP = app.getResetValue(UsicSfruri);  
   String actINPR_TSINP = app.getMuxValue(UsicSfruri); 
   if((actINPR_TSINP.compareTo(rstINPR_TSINP) != 0) && (actINPR_TSINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_526);
    stringBuffer.append(actINPR_TSINP);
    stringBuffer.append(TEXT_527);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_528);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_529);
    stringBuffer.append(actINPR_TSINP);
    stringBuffer.append(TEXT_530);
     } 
    stringBuffer.append(TEXT_531);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/inpr_tbinp" ; 
   String rstINPR_TBINP = app.getResetValue(UsicSfruri); 
   String actINPR_TBINP = app.getMuxValue(UsicSfruri);                
   if((actINPR_TBINP.compareTo(rstINPR_TBINP) != 0) && (actINPR_TBINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_532);
    stringBuffer.append(actINPR_TBINP);
    stringBuffer.append(TEXT_533);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_534);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_535);
    stringBuffer.append(actINPR_TBINP);
    stringBuffer.append(TEXT_536);
     } 
    stringBuffer.append(TEXT_537);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/inpr_rinp" ; 
   String rstINPR_RINP = app.getResetValue(UsicSfruri);
   String actINPR_RINP = app.getMuxValue(UsicSfruri);               
   if((actINPR_RINP.compareTo(rstINPR_RINP) != 0) && (actINPR_RINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_538);
    stringBuffer.append(actINPR_RINP);
    stringBuffer.append(TEXT_539);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_540);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_541);
    stringBuffer.append(actINPR_RINP);
    stringBuffer.append(TEXT_542);
     } 
    stringBuffer.append(TEXT_543);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/inpr_ainp" ;  
   String rstINPR_AINP = app.getResetValue(UsicSfruri); 
   String actINPR_AINP = app.getMuxValue(UsicSfruri);                
  if((actINPR_AINP.compareTo(rstINPR_AINP) != 0) && (actINPR_AINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_544);
    stringBuffer.append(actINPR_AINP);
    stringBuffer.append(TEXT_545);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_546);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_547);
    stringBuffer.append(actINPR_AINP);
    stringBuffer.append(TEXT_548);
     } 
    stringBuffer.append(TEXT_549);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/inpr_pinp" ;  
   String rstINPR_PINP = app.getResetValue(UsicSfruri); 
   String actINPR_PINP = app.getMuxValue(UsicSfruri);                
   if((actINPR_PINP.compareTo(rstINPR_PINP) != 0) && (actINPR_PINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_550);
    stringBuffer.append(actINPR_PINP);
    stringBuffer.append(TEXT_551);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_552);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_553);
    stringBuffer.append(actINPR_PINP);
    stringBuffer.append(TEXT_554);
     } 
    stringBuffer.append(TEXT_555);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/tbctr_stbinp" ;
   String rstTBCTR_STBINP = app.getResetValue(UsicSfruri); 
   String actTBCTR_STBINP = app.getMuxValue(UsicSfruri);
   if((actTBCTR_STBINP.compareTo(rstTBCTR_STBINP) != 0) && (actTBCTR_STBINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_556);
    stringBuffer.append(actTBCTR_STBINP);
    stringBuffer.append(TEXT_557);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_558);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_559);
    stringBuffer.append(actTBCTR_STBINP);
    stringBuffer.append(TEXT_560);
     } 
    stringBuffer.append(TEXT_561);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/tbctr_atbinp" ; 
   String rstTBCTR_ATBINP = app.getResetValue(UsicSfruri); 
   String actTBCTR_ATBINP = app.getMuxValue(UsicSfruri);             
   if((actTBCTR_ATBINP.compareTo(rstTBCTR_ATBINP) != 0) && (actTBCTR_ATBINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_562);
    stringBuffer.append(actTBCTR_ATBINP);
    stringBuffer.append(TEXT_563);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_564);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_565);
    stringBuffer.append(actTBCTR_ATBINP);
    stringBuffer.append(TEXT_566);
     } 
    stringBuffer.append(TEXT_567);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/rbctr_srbinp" ; 
   String rstRBCTR_SRBINP = app.getResetValue(UsicSfruri); 
   String actRBCTR_SRBINP = app.getMuxValue(UsicSfruri);               
  if((actRBCTR_SRBINP.compareTo(rstRBCTR_SRBINP) != 0) && (actRBCTR_SRBINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_568);
    stringBuffer.append(actRBCTR_SRBINP);
    stringBuffer.append(TEXT_569);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_570);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_571);
    stringBuffer.append(actRBCTR_SRBINP);
    stringBuffer.append(TEXT_572);
     } 
    stringBuffer.append(TEXT_573);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/rbctr_arbinp" ; 
   String rstRBCTR_ARBINP = app.getResetValue(UsicSfruri); 
   String actRBCTR_ARBINP = app.getMuxValue(UsicSfruri);              
   if((actRBCTR_ARBINP.compareTo(rstRBCTR_ARBINP) != 0) && (actRBCTR_ARBINP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_574);
    stringBuffer.append(actRBCTR_ARBINP);
    stringBuffer.append(TEXT_575);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_576);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_577);
    stringBuffer.append(actRBCTR_ARBINP);
    stringBuffer.append(TEXT_578);
     } 
    stringBuffer.append(TEXT_579);
    int txactdptr = 0;
    int txactsize = 0;
    stringBuffer.append(TEXT_580);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/tbctr_dptr" ; 
   String rst = app.getResetValue(UsicSfruri); 
   String act = app.getMuxValue(UsicSfruri);              
   if((act.compareTo(rst) != 0) && (act.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_581);
    txactdptr = Integer.parseInt(act);
    stringBuffer.append(TEXT_582);
     } 
    stringBuffer.append(TEXT_583);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/tbctr_size" ; 
   rst = app.getResetValue(UsicSfruri); 
   act = app.getMuxValue(UsicSfruri);              
   if((act.compareTo(rst) != 0) && (act.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_584);
    txactsize = Integer.parseInt(act);
     } 
    stringBuffer.append(TEXT_585);
     if((txactdptr != 0) || (txactsize != 0)) { 
    stringBuffer.append(TEXT_586);
    int txactdptrsize = (txactdptr + (txactsize << 24));
    stringBuffer.append(TEXT_587);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_588);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_589);
    stringBuffer.append( Integer.toHexString(txactdptrsize));
    stringBuffer.append(TEXT_590);
    stringBuffer.append(txactdptr);
    stringBuffer.append(TEXT_591);
    stringBuffer.append(txactsize);
    stringBuffer.append(TEXT_592);
     } 
    int rxactdptr = 0;
    int rxactsize = 0;
    stringBuffer.append(TEXT_593);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/rbctr_dptr" ; 
   rst = app.getResetValue(UsicSfruri); 
   act = app.getMuxValue(UsicSfruri);              
   if((act.compareTo(rst) != 0) && (act.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_594);
    rxactdptr = Integer.parseInt(act);
    stringBuffer.append(TEXT_595);
     } 
    stringBuffer.append(TEXT_596);
     UsicSfruri =  UsicBaseuri + k + "/channel/" + l + "/rbctr_size" ; 
   rst = app.getResetValue(UsicSfruri); 
   act = app.getMuxValue(UsicSfruri);              
  if((act.compareTo(rst) != 0) && (act.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_597);
    rxactsize = Integer.parseInt(act);
    stringBuffer.append(TEXT_598);
     } 
    stringBuffer.append(TEXT_599);
     if((rxactdptr != 0) || (rxactsize != 0)) { 
    stringBuffer.append(TEXT_600);
    int rxactdptrsize = (rxactdptr + (rxactsize << 24));
    stringBuffer.append(TEXT_601);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_602);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_603);
    stringBuffer.append( Integer.toHexString(rxactdptrsize));
    stringBuffer.append(TEXT_604);
    stringBuffer.append(rxactdptr);
    stringBuffer.append(TEXT_605);
    stringBuffer.append(rxactsize);
    stringBuffer.append(TEXT_606);
     } 
    } 
    stringBuffer.append(TEXT_607);
    } 
    stringBuffer.append(TEXT_608);
     } 
     //********* USIC CONFIGURATIONS ---  END ************************* 
     //********* MODULE DLR CONFIGURATIONS BEGIN ************************* 
    stringBuffer.append(TEXT_609);
    if(MyTempPeriName.compareTo("peripheral/dlr") == 0) {
    stringBuffer.append(TEXT_610);
     int DlrChannel = 12;
   String DlrBaseuri = "";
   String DlrSfruri = "";
   int k = 0;
   DlrBaseuri = "peripheral/dlr/0";
    stringBuffer.append(TEXT_611);
     for (int l=0; l< DlrChannel; l++) { 
     if  (l < 8) { 
    stringBuffer.append(TEXT_612);
     k = 0;
    stringBuffer.append(TEXT_613);
     } else {
    stringBuffer.append(TEXT_614);
     k = 1;
    stringBuffer.append(TEXT_615);
     } 
    stringBuffer.append(TEXT_616);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_617);
     DlrSfruri =  DlrBaseuri + "/ch/" + l + "/srsel_rs" ;  
         String rstSRSEL_RS = app.getResetValue(DlrSfruri); 
      	 String actSRSEL_RS = app.getMuxValue(DlrSfruri);    
         if((actSRSEL_RS.compareTo(rstSRSEL_RS) != 0) && (actSRSEL_RS.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_618);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_619);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_620);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_621);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_622);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_623);
    stringBuffer.append(actSRSEL_RS);
    stringBuffer.append(TEXT_624);
     } 
    stringBuffer.append(TEXT_625);
    } 
    stringBuffer.append(TEXT_626);
     } 
    stringBuffer.append(TEXT_627);
     //********* DLR CONFIGURATIONS ---  END ************************* 
    stringBuffer.append(TEXT_628);
     //********* MODULE DMA CONFIGURATIONS BEGIN ************************* 
    stringBuffer.append(TEXT_629);
    if((MyTempPeriName.compareTo("peripheral/dma8") == 0) || (MyTempPeriName.compareTo("peripheral/dma4") == 0)) {
    stringBuffer.append(TEXT_630);
     int DmaNum = 2;
      int DmaChannel = 12;					
      String DmaBaseuri = "";					
      String DmaSfruri = "";
      String Channel = "";
      String Dma = "dma8";
    if((MyTempPeriName.compareTo("peripheral/dma8") == 0)) {
     DmaNum = 0;
     } 
    stringBuffer.append(TEXT_631);
    if((MyTempPeriName.compareTo("peripheral/dma4") == 0)) {
     DmaNum = 1;
     } 
    stringBuffer.append(TEXT_632);
    stringBuffer.append(DmaNum);
    stringBuffer.append(TEXT_633);
     for (int k=DmaNum; k<=DmaNum; k++) { 
    stringBuffer.append(TEXT_634);
     if  (k < 1) { 
    stringBuffer.append(TEXT_635);
     DmaChannel = 8;
    Dma = "dma8";
    DmaBaseuri = "peripheral/" + Dma + "/";
    stringBuffer.append(TEXT_636);
     } else {
    stringBuffer.append(TEXT_637);
     DmaChannel = 4;  
    Dma = "dma4";
    DmaBaseuri = "peripheral/" + Dma + "/";
    stringBuffer.append(TEXT_638);
     } 
    stringBuffer.append(TEXT_639);
     for (int l=0; l< DmaChannel; l++) { 
    stringBuffer.append(TEXT_640);
     if ( (l < 2) && (k < 1)  ) { 
    stringBuffer.append(TEXT_641);
     Channel = "ch_adv";
     } else {
    stringBuffer.append(TEXT_642);
     Channel = "ch";
    stringBuffer.append(TEXT_643);
     } 
    stringBuffer.append(TEXT_644);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_645);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_646);
     int j = 0;
    stringBuffer.append(TEXT_647);
     DmaSfruri =  DmaBaseuri + j + "/" + Channel + "/" + l + "/cfgl_hs_sel_src" ;  
  String rstCFGL_HS_SEL_SRC = app.getResetValue(DmaSfruri); 
  String actCFGL_HS_SEL_SRC = app.getMuxValue(DmaSfruri); 
     if((actCFGL_HS_SEL_SRC.compareTo(rstCFGL_HS_SEL_SRC) != 0) && (actCFGL_HS_SEL_SRC.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_648);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_649);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_650);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_651);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_652);
    stringBuffer.append(actCFGL_HS_SEL_SRC);
    stringBuffer.append(TEXT_653);
     } 
    stringBuffer.append(TEXT_654);
     DmaSfruri =  DmaBaseuri + j + "/" + Channel + "/" + l + "/cfgl_hs_sel_dst" ;  
  String rstCFGL_HS_SEL_DST = app.getResetValue(DmaSfruri); 
  String actCFGL_HS_SEL_DST = app.getMuxValue(DmaSfruri); 
    stringBuffer.append(TEXT_655);
     if((actCFGL_HS_SEL_DST.compareTo(rstCFGL_HS_SEL_DST) != 0) && (actCFGL_HS_SEL_DST.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_656);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_657);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_658);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_659);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_660);
    stringBuffer.append(actCFGL_HS_SEL_DST);
    stringBuffer.append(TEXT_661);
     } 
     DmaSfruri =  DmaBaseuri + j + "/" + Channel + "/" + l + "/cfgh_src_per" ;  
  String rstCFGH_SRC_PER = app.getResetValue(DmaSfruri);
  String actCFGH_SRC_PER = app.getMuxValue(DmaSfruri); 
    stringBuffer.append(TEXT_662);
     if((actCFGH_SRC_PER.compareTo(rstCFGH_SRC_PER) != 0) && (actCFGH_SRC_PER.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_663);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_664);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_665);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_666);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_667);
    stringBuffer.append(actCFGH_SRC_PER);
    stringBuffer.append(TEXT_668);
     } 
     DmaSfruri =  DmaBaseuri + j + "/" + Channel + "/" + l + "/cfgh_dest_per" ; 
  String rstCFGH_DEST_PER = app.getResetValue(DmaSfruri); 
  String actCFGH_DEST_PER = app.getMuxValue(DmaSfruri); 
    stringBuffer.append(TEXT_669);
     if((actCFGH_DEST_PER.compareTo(rstCFGH_DEST_PER) != 0) && (actCFGH_DEST_PER.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_670);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_671);
    stringBuffer.append(l);
    stringBuffer.append(TEXT_672);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_673);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_674);
    stringBuffer.append(actCFGH_DEST_PER);
    stringBuffer.append(TEXT_675);
     } 
    stringBuffer.append(TEXT_676);
    } 
    } 
    stringBuffer.append(TEXT_677);
     } 
    stringBuffer.append(TEXT_678);
     //********* DMA CONFIGURATIONS ---  END ************************* 
     //********* MODULE VADC CONFIGURATIONS BEGIN ************************* 
    if(MyTempPeriName.compareTo("peripheral/vadc") == 0) {
     int VadcGroup = 4; 
               int VadcChannel = 8;
               String VadcBaseuri = "peripheral/vadc/";
               String VadcSfruri = "";
    stringBuffer.append(TEXT_679);
     for (int k=0; k< VadcGroup; k++) { 
    stringBuffer.append(TEXT_680);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_681);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/queue" + "/gqctrl0_xtsel";
    stringBuffer.append(TEXT_682);
     String rstGQCTRL0_XTSEL = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_683);
     String actGQCTRL0_XTSEL = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_684);
     if((actGQCTRL0_XTSEL.compareTo(rstGQCTRL0_XTSEL) != 0) && (actGQCTRL0_XTSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_685);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_686);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_687);
    stringBuffer.append(actGQCTRL0_XTSEL);
    stringBuffer.append(TEXT_688);
     } 
    stringBuffer.append(TEXT_689);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/scan" + "/gasctrl_xtsel";
    stringBuffer.append(TEXT_690);
     String rstGASCTRL_XTSEL = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_691);
     String actGASCTRL_XTSEL = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_692);
     if((actGASCTRL_XTSEL.compareTo(rstGASCTRL_XTSEL) != 0) && (actGASCTRL_XTSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_693);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_694);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_695);
    stringBuffer.append(actGASCTRL_XTSEL);
    stringBuffer.append(TEXT_696);
     } 
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/queue" + "/gqctrl0_gtsel";
    stringBuffer.append(TEXT_697);
     String rstGQCTRL0_GTSEL = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_698);
     String actGQCTRL0_GTSEL = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_699);
     if((actGQCTRL0_GTSEL.compareTo(rstGQCTRL0_GTSEL) != 0) && (actGQCTRL0_GTSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_700);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_701);
    stringBuffer.append(actGQCTRL0_GTSEL);
    stringBuffer.append(TEXT_702);
     } 
    stringBuffer.append(TEXT_703);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/scan" + "/gasctrl_gtsel";
    stringBuffer.append(TEXT_704);
     String rstGASCTRL_GTSEL = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_705);
     String actGASCTRL_GTSEL = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_706);
     if((actGASCTRL_GTSEL.compareTo(rstGASCTRL_GTSEL) != 0) && (actGASCTRL_GTSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_707);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_708);
    stringBuffer.append(actGASCTRL_GTSEL);
    stringBuffer.append(TEXT_709);
     } 
    stringBuffer.append(TEXT_710);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/queue" + "/gsevnp_sev0np";
    stringBuffer.append(TEXT_711);
     String rstGSEVNP_SEV0NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_712);
     String actGSEVNP_SEV0NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_713);
     if((actGSEVNP_SEV0NP.compareTo(rstGSEVNP_SEV0NP) != 0) && (actGSEVNP_SEV0NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_714);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_715);
    stringBuffer.append(actGSEVNP_SEV0NP);
    stringBuffer.append(TEXT_716);
     } 
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/scan" + "/gsevnp_sev1np";
    stringBuffer.append(TEXT_717);
     String rstGSEVNP_SEV1NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_718);
     String actGSEVNP_SEV1NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_719);
     if((actGSEVNP_SEV1NP.compareTo(rstGSEVNP_SEV1NP) != 0) && (actGSEVNP_SEV1NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_720);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_721);
    stringBuffer.append(actGSEVNP_SEV1NP);
    stringBuffer.append(TEXT_722);
     } 
    stringBuffer.append(TEXT_723);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/sync" + "/gsynctr_stsel";
    stringBuffer.append(TEXT_724);
     String rstGSYNCTR_STSEL = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_725);
     String actGSYNCTR_STSEL = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_726);
     if((actGSYNCTR_STSEL.compareTo(rstGSYNCTR_STSEL) != 0) && (actGSYNCTR_STSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_727);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_728);
    stringBuffer.append(actGSYNCTR_STSEL);
    stringBuffer.append(TEXT_729);
     } 
    stringBuffer.append(TEXT_730);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/sync" + "/gsynctr_evalr1";
    stringBuffer.append(TEXT_731);
     String rstGSYNCTR_EVALR1 = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_732);
     String actGSYNCTR_EVALR1 = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_733);
     if((actGSYNCTR_EVALR1.compareTo(rstGSYNCTR_EVALR1) != 0) && (actGSYNCTR_EVALR1.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_734);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_735);
    stringBuffer.append(actGSYNCTR_EVALR1);
    stringBuffer.append(TEXT_736);
     } 
    stringBuffer.append(TEXT_737);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/sync" + "/gsynctr_evalr2";
    stringBuffer.append(TEXT_738);
     String rstGSYNCTR_EVALR2 = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_739);
     String actGSYNCTR_EVALR2 = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_740);
     if((actGSYNCTR_EVALR2.compareTo(rstGSYNCTR_EVALR2) != 0) && (actGSYNCTR_EVALR2.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_741);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_742);
    stringBuffer.append(actGSYNCTR_EVALR2);
    stringBuffer.append(TEXT_743);
     } 
    stringBuffer.append(TEXT_744);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/sync" + "/gsynctr_evalr3";
    stringBuffer.append(TEXT_745);
     String rstGSYNCTR_EVALR3 = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_746);
     String actGSYNCTR_EVALR3 = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_747);
     if((actGSYNCTR_EVALR3.compareTo(rstGSYNCTR_EVALR3) != 0) && (actGSYNCTR_EVALR3.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_748);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_749);
    stringBuffer.append(actGSYNCTR_EVALR3);
    stringBuffer.append(TEXT_750);
     } 
    stringBuffer.append(TEXT_751);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/0" + "/galias_alias0";
    stringBuffer.append(TEXT_752);
     String rstGALIAS_ALIAS0 = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_753);
     String actGALIAS_ALIAS0 = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_754);
     if((actGALIAS_ALIAS0.compareTo(rstGALIAS_ALIAS0) != 0) && (actGALIAS_ALIAS0.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_755);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_756);
    stringBuffer.append(actGALIAS_ALIAS0);
    stringBuffer.append(TEXT_757);
     } 
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/1" + "/galias_alias1";
    stringBuffer.append(TEXT_758);
     String rstGALIAS_ALIAS1 = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_759);
     String actGALIAS_ALIAS1 = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_760);
     if((actGALIAS_ALIAS1.compareTo(rstGALIAS_ALIAS1) != 0) && (actGALIAS_ALIAS1.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_761);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_762);
    stringBuffer.append(actGALIAS_ALIAS1);
    stringBuffer.append(TEXT_763);
     } 
    stringBuffer.append(TEXT_764);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/0" + "/gchctr_resreg";
    stringBuffer.append(TEXT_765);
     String rstGCHCTR0_RESREG = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_766);
     String actGCHCTR0_RESREG = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_767);
     if((actGCHCTR0_RESREG.compareTo(rstGCHCTR0_RESREG) != 0) && (actGCHCTR0_RESREG.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_768);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_769);
    stringBuffer.append(actGCHCTR0_RESREG);
    stringBuffer.append(TEXT_770);
     } 
    stringBuffer.append(TEXT_771);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/1" + "/gchctr_resreg";
    stringBuffer.append(TEXT_772);
     String rstGCHCTR1_RESREG = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_773);
     String actGCHCTR1_RESREG = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_774);
     if((actGCHCTR1_RESREG.compareTo(rstGCHCTR1_RESREG) != 0) && (actGCHCTR1_RESREG.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_775);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_776);
    stringBuffer.append(actGCHCTR1_RESREG);
    stringBuffer.append(TEXT_777);
     } 
    stringBuffer.append(TEXT_778);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/2" + "/gchctr_resreg";
    stringBuffer.append(TEXT_779);
     String rstGCHCTR2_RESREG = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_780);
     String actGCHCTR2_RESREG = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_781);
     if((actGCHCTR2_RESREG.compareTo(rstGCHCTR2_RESREG) != 0) && (actGCHCTR2_RESREG.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_782);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_783);
    stringBuffer.append(actGCHCTR2_RESREG);
    stringBuffer.append(TEXT_784);
     } 
    stringBuffer.append(TEXT_785);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/3" + "/gchctr_resreg";
    stringBuffer.append(TEXT_786);
     String rstGCHCTR3_RESREG = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_787);
     String actGCHCTR3_RESREG = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_788);
     if((actGCHCTR3_RESREG.compareTo(rstGCHCTR3_RESREG) != 0) && (actGCHCTR3_RESREG.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_789);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_790);
    stringBuffer.append(actGCHCTR3_RESREG);
    stringBuffer.append(TEXT_791);
     } 
    stringBuffer.append(TEXT_792);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/4" + "/gchctr_resreg";
    stringBuffer.append(TEXT_793);
     String rstGCHCTR4_RESREG = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_794);
     String actGCHCTR4_RESREG = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_795);
     if((actGCHCTR4_RESREG.compareTo(rstGCHCTR4_RESREG) != 0) && (actGCHCTR4_RESREG.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_796);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_797);
    stringBuffer.append(actGCHCTR4_RESREG);
    stringBuffer.append(TEXT_798);
     } 
    stringBuffer.append(TEXT_799);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/5" + "/gchctr_resreg";
    stringBuffer.append(TEXT_800);
     String rstGCHCTR5_RESREG = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_801);
     String actGCHCTR5_RESREG = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_802);
     if((actGCHCTR5_RESREG.compareTo(rstGCHCTR5_RESREG) != 0) && (actGCHCTR5_RESREG.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_803);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_804);
    stringBuffer.append(actGCHCTR5_RESREG);
    stringBuffer.append(TEXT_805);
     } 
    stringBuffer.append(TEXT_806);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/6" + "/gchctr_resreg";
    stringBuffer.append(TEXT_807);
     String rstGCHCTR6_RESREG = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_808);
     String actGCHCTR6_RESREG = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_809);
     if((actGCHCTR6_RESREG.compareTo(rstGCHCTR6_RESREG) != 0) && (actGCHCTR6_RESREG.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_810);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_811);
    stringBuffer.append(actGCHCTR6_RESREG);
    stringBuffer.append(TEXT_812);
     } 
    stringBuffer.append(TEXT_813);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/7" + "/gchctr_resreg";
    stringBuffer.append(TEXT_814);
     String rstGCHCTR7_RESREG = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_815);
     String actGCHCTR7_RESREG = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_816);
     if((actGCHCTR7_RESREG.compareTo(rstGCHCTR7_RESREG) != 0) && (actGCHCTR7_RESREG.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_817);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_818);
    stringBuffer.append(actGCHCTR7_RESREG);
    stringBuffer.append(TEXT_819);
     } 
    stringBuffer.append(TEXT_820);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/0" + "/gcevnp0_cevnp";
    stringBuffer.append(TEXT_821);
     String rstGCEVNP0_CEV0NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_822);
     String actGCEVNP0_CEV0NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_823);
     if((actGCEVNP0_CEV0NP.compareTo(rstGCEVNP0_CEV0NP) != 0) && (actGCEVNP0_CEV0NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_824);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_825);
    stringBuffer.append(actGCEVNP0_CEV0NP);
    stringBuffer.append(TEXT_826);
     } 
    stringBuffer.append(TEXT_827);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/1" + "/gcevnp0_cevnp";
    stringBuffer.append(TEXT_828);
     String rstGCEVNP0_CEV1NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_829);
     String actGCEVNP0_CEV1NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_830);
     if((actGCEVNP0_CEV1NP.compareTo(rstGCEVNP0_CEV1NP) != 0) && (actGCEVNP0_CEV1NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_831);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_832);
    stringBuffer.append(actGCEVNP0_CEV1NP);
    stringBuffer.append(TEXT_833);
     } 
    stringBuffer.append(TEXT_834);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/2" + "/gcevnp0_cevnp";
    stringBuffer.append(TEXT_835);
     String rstGCEVNP0_CEV2NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_836);
     String actGCEVNP0_CEV2NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_837);
     if((actGCEVNP0_CEV2NP.compareTo(rstGCEVNP0_CEV2NP) != 0) && (actGCEVNP0_CEV2NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_838);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_839);
    stringBuffer.append(actGCEVNP0_CEV2NP);
    stringBuffer.append(TEXT_840);
     } 
    stringBuffer.append(TEXT_841);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/3" + "/gcevnp0_cevnp";
    stringBuffer.append(TEXT_842);
     String rstGCEVNP0_CEV3NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_843);
     String actGCEVNP0_CEV3NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_844);
     if((actGCEVNP0_CEV3NP.compareTo(rstGCEVNP0_CEV3NP) != 0) && (actGCEVNP0_CEV3NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_845);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_846);
    stringBuffer.append(actGCEVNP0_CEV3NP);
    stringBuffer.append(TEXT_847);
     } 
    stringBuffer.append(TEXT_848);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/4" + "/gcevnp0_cevnp";
    stringBuffer.append(TEXT_849);
     String rstGCEVNP0_CEV4NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_850);
     String actGCEVNP0_CEV4NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_851);
     if((actGCEVNP0_CEV4NP.compareTo(rstGCEVNP0_CEV4NP) != 0) && (actGCEVNP0_CEV4NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_852);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_853);
    stringBuffer.append(actGCEVNP0_CEV4NP);
    stringBuffer.append(TEXT_854);
     } 
    stringBuffer.append(TEXT_855);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/5" + "/gcevnp0_cevnp";
    stringBuffer.append(TEXT_856);
     String rstGCEVNP0_CEV5NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_857);
     String actGCEVNP0_CEV5NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_858);
     if((actGCEVNP0_CEV5NP.compareTo(rstGCEVNP0_CEV5NP) != 0) && (actGCEVNP0_CEV5NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_859);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_860);
    stringBuffer.append(actGCEVNP0_CEV5NP);
    stringBuffer.append(TEXT_861);
     } 
    stringBuffer.append(TEXT_862);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/6" + "/gcevnp0_cevnp";
    stringBuffer.append(TEXT_863);
     String rstGCEVNP0_CEV6NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_864);
     String actGCEVNP0_CEV6NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_865);
     if((actGCEVNP0_CEV6NP.compareTo(rstGCEVNP0_CEV6NP) != 0) && (actGCEVNP0_CEV6NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_866);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_867);
    stringBuffer.append(actGCEVNP0_CEV6NP);
    stringBuffer.append(TEXT_868);
     } 
    stringBuffer.append(TEXT_869);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/ch/7" + "/gcevnp0_cevnp";
    stringBuffer.append(TEXT_870);
     String rstGCEVNP0_CEV7NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_871);
     String actGCEVNP0_CEV7NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_872);
     if((actGCEVNP0_CEV7NP.compareTo(rstGCEVNP0_CEV7NP) != 0) && (actGCEVNP0_CEV7NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_873);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_874);
    stringBuffer.append(actGCEVNP0_CEV7NP);
    stringBuffer.append(TEXT_875);
     } 
    stringBuffer.append(TEXT_876);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result_adv/0" + "/grevnp0_rev0np";
    stringBuffer.append(TEXT_877);
     String rstGREVNP0_REV0NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_878);
     String actGREVNP0_REV0NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_879);
     if((actGREVNP0_REV0NP.compareTo(rstGREVNP0_REV0NP) != 0) && (actGREVNP0_REV0NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_880);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_881);
    stringBuffer.append(actGREVNP0_REV0NP);
    stringBuffer.append(TEXT_882);
     } 
    stringBuffer.append(TEXT_883);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result_adv/1" + "/grevnp0_rev1np";
    stringBuffer.append(TEXT_884);
     String rstGREVNP0_REV1NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_885);
     String actGREVNP0_REV1NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_886);
     if((actGREVNP0_REV1NP.compareTo(rstGREVNP0_REV1NP) != 0) && (actGREVNP0_REV1NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_887);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_888);
    stringBuffer.append(actGREVNP0_REV1NP);
    stringBuffer.append(TEXT_889);
     } 
    stringBuffer.append(TEXT_890);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result_adv/2" + "/grevnp0_rev2np";
    stringBuffer.append(TEXT_891);
     String rstGREVNP0_REV2NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_892);
     String actGREVNP0_REV2NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_893);
     if((actGREVNP0_REV2NP.compareTo(rstGREVNP0_REV2NP) != 0) && (actGREVNP0_REV2NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_894);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_895);
    stringBuffer.append(actGREVNP0_REV2NP);
    stringBuffer.append(TEXT_896);
     } 
    stringBuffer.append(TEXT_897);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result_adv/3" + "/grevnp0_rev3np";
    stringBuffer.append(TEXT_898);
     String rstGREVNP0_REV3NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_899);
     String actGREVNP0_REV3NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_900);
     if((actGREVNP0_REV3NP.compareTo(rstGREVNP0_REV3NP) != 0) && (actGREVNP0_REV3NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_901);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_902);
    stringBuffer.append(actGREVNP0_REV3NP);
    stringBuffer.append(TEXT_903);
     } 
    stringBuffer.append(TEXT_904);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/4" + "/grevnp0_rev4np";
    stringBuffer.append(TEXT_905);
     String rstGREVNP0_REV4NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_906);
     String actGREVNP0_REV4NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_907);
     if((actGREVNP0_REV4NP.compareTo(rstGREVNP0_REV4NP) != 0) && (actGREVNP0_REV4NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_908);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_909);
    stringBuffer.append(actGREVNP0_REV4NP);
    stringBuffer.append(TEXT_910);
     } 
    stringBuffer.append(TEXT_911);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/5" + "/grevnp0_rev5np";
    stringBuffer.append(TEXT_912);
     String rstGREVNP0_REV5NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_913);
     String actGREVNP0_REV5NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_914);
     if((actGREVNP0_REV5NP.compareTo(rstGREVNP0_REV5NP) != 0) && (actGREVNP0_REV5NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_915);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_916);
    stringBuffer.append(actGREVNP0_REV5NP);
    stringBuffer.append(TEXT_917);
     } 
    stringBuffer.append(TEXT_918);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/6" + "/grevnp0_rev6np";
    stringBuffer.append(TEXT_919);
     String rstGREVNP0_REV6NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_920);
     String actGREVNP0_REV6NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_921);
     if((actGREVNP0_REV6NP.compareTo(rstGREVNP0_REV6NP) != 0) && (actGREVNP0_REV6NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_922);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_923);
    stringBuffer.append(actGREVNP0_REV6NP);
    stringBuffer.append(TEXT_924);
     } 
    stringBuffer.append(TEXT_925);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result_filter/7" + "/grevnp0_rev7np";
    stringBuffer.append(TEXT_926);
     String rstGREVNP0_REV7NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_927);
     String actGREVNP0_REV7NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_928);
     if((actGREVNP0_REV7NP.compareTo(rstGREVNP0_REV7NP) != 0) && (actGREVNP0_REV7NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_929);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_930);
    stringBuffer.append(actGREVNP0_REV7NP);
    stringBuffer.append(TEXT_931);
     } 
    stringBuffer.append(TEXT_932);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/8" + "/grevnp1_rev8np";
    stringBuffer.append(TEXT_933);
     String rstGREVNP1_REV8NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_934);
     String actGREVNP1_REV8NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_935);
     if((actGREVNP1_REV8NP.compareTo(rstGREVNP1_REV8NP) != 0) && (actGREVNP1_REV8NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_936);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_937);
    stringBuffer.append(actGREVNP1_REV8NP);
    stringBuffer.append(TEXT_938);
     } 
    stringBuffer.append(TEXT_939);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/9" + "/grevnp1_rev9np";
    stringBuffer.append(TEXT_940);
     String rstGREVNP1_REV9NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_941);
     String actGREVNP1_REV9NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_942);
     if((actGREVNP1_REV9NP.compareTo(rstGREVNP1_REV9NP) != 0) && (actGREVNP1_REV9NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_943);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_944);
    stringBuffer.append(actGREVNP1_REV9NP);
    stringBuffer.append(TEXT_945);
     } 
    stringBuffer.append(TEXT_946);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/10" + "/grevnp1_rev10np";
    stringBuffer.append(TEXT_947);
     String rstGREVNP1_REV10NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_948);
     String actGREVNP1_REV10NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_949);
     if((actGREVNP1_REV10NP.compareTo(rstGREVNP1_REV10NP) != 0) && (actGREVNP1_REV10NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_950);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_951);
    stringBuffer.append(actGREVNP1_REV10NP);
    stringBuffer.append(TEXT_952);
     } 
    stringBuffer.append(TEXT_953);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/11" + "/grevnp1_rev11np";
    stringBuffer.append(TEXT_954);
     String rstGREVNP1_REV11NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_955);
     String actGREVNP1_REV11NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_956);
     if((actGREVNP1_REV11NP.compareTo(rstGREVNP1_REV11NP) != 0) && (actGREVNP1_REV11NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_957);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_958);
    stringBuffer.append(actGREVNP1_REV11NP);
    stringBuffer.append(TEXT_959);
     } 
    stringBuffer.append(TEXT_960);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/12" + "/grevnp1_rev12np";
    stringBuffer.append(TEXT_961);
     String rstGREVNP1_REV12NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_962);
     String actGREVNP1_REV12NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_963);
     if((actGREVNP1_REV12NP.compareTo(rstGREVNP1_REV12NP) != 0) && (actGREVNP1_REV12NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_964);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_965);
    stringBuffer.append(actGREVNP1_REV12NP);
    stringBuffer.append(TEXT_966);
     } 
    stringBuffer.append(TEXT_967);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/13" + "/grevnp1_rev13np";
    stringBuffer.append(TEXT_968);
     String rstGREVNP1_REV13NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_969);
     String actGREVNP1_REV13NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_970);
     if((actGREVNP1_REV13NP.compareTo(rstGREVNP1_REV13NP) != 0) && (actGREVNP1_REV13NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_971);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_972);
    stringBuffer.append(actGREVNP1_REV13NP);
    stringBuffer.append(TEXT_973);
     } 
    stringBuffer.append(TEXT_974);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result/14" + "/grevnp1_rev14np";
    stringBuffer.append(TEXT_975);
     String rstGREVNP1_REV14NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_976);
     String actGREVNP1_REV14NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_977);
     if((actGREVNP1_REV14NP.compareTo(rstGREVNP1_REV14NP) != 0) && (actGREVNP1_REV14NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_978);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_979);
    stringBuffer.append(actGREVNP1_REV14NP);
    stringBuffer.append(TEXT_980);
     } 
    stringBuffer.append(TEXT_981);
     VadcSfruri =  VadcBaseuri + 0 + "/group/" + k + "/result_filter/15" + "/grevnp1_rev15np";
    stringBuffer.append(TEXT_982);
     String rstGREVNP1_REV15NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_983);
     String actGREVNP1_REV15NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_984);
     if((actGREVNP1_REV15NP.compareTo(rstGREVNP1_REV15NP) != 0) && (actGREVNP1_REV15NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_985);
    stringBuffer.append(k);
    stringBuffer.append(TEXT_986);
    stringBuffer.append(actGREVNP1_REV15NP);
    stringBuffer.append(TEXT_987);
     } 
    stringBuffer.append(TEXT_988);
     } 
    stringBuffer.append(TEXT_989);
     VadcSfruri =  VadcBaseuri + 0 + "/global_result" + "/globevnp_rev0np";
    stringBuffer.append(TEXT_990);
     String rstGLOBEVNP_REV0NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_991);
     String actGLOBEVNP_REV0NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_992);
     if((actGLOBEVNP_REV0NP.compareTo(rstGLOBEVNP_REV0NP) != 0) && (actGLOBEVNP_REV0NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_993);
    stringBuffer.append(actGLOBEVNP_REV0NP);
    stringBuffer.append(TEXT_994);
     } 
    stringBuffer.append(TEXT_995);
     VadcSfruri =  VadcBaseuri + 0 + "/global/emuxsel_emuxgrp0";
    stringBuffer.append(TEXT_996);
     String rstEMUXSEL_EMUXGRP0 = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_997);
     String actEMUXSEL_EMUXGRP0 = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_998);
     if((actEMUXSEL_EMUXGRP0.compareTo(rstEMUXSEL_EMUXGRP0) != 0) && (actEMUXSEL_EMUXGRP0.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_999);
    stringBuffer.append(actEMUXSEL_EMUXGRP0);
    stringBuffer.append(TEXT_1000);
     } 
    stringBuffer.append(TEXT_1001);
     VadcSfruri =  VadcBaseuri + 0 + "/global/emuxsel_emuxgrp1";
    stringBuffer.append(TEXT_1002);
     String rstEMUXSEL_EMUXGRP1 = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_1003);
     String actEMUXSEL_EMUXGRP1 = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_1004);
     if((actEMUXSEL_EMUXGRP1.compareTo(rstEMUXSEL_EMUXGRP1) != 0) && (actEMUXSEL_EMUXGRP1.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1005);
    stringBuffer.append(actEMUXSEL_EMUXGRP1);
    stringBuffer.append(TEXT_1006);
     } 
    stringBuffer.append(TEXT_1007);
     VadcSfruri =  VadcBaseuri + 0 + "/backgnd" + "/brsctrl_xtsel";
    stringBuffer.append(TEXT_1008);
     String rstBRSCTRL_XTSEL = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_1009);
     String actBRSCTRL_XTSEL = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_1010);
     if((actBRSCTRL_XTSEL.compareTo(rstBRSCTRL_XTSEL) != 0) && (actBRSCTRL_XTSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1011);
    stringBuffer.append(actBRSCTRL_XTSEL);
    stringBuffer.append(TEXT_1012);
     } 
    stringBuffer.append(TEXT_1013);
     VadcSfruri =  VadcBaseuri + 0 + "/backgnd" + "/brsctrl_gtsel";
    stringBuffer.append(TEXT_1014);
     String rstBRSCTRL_GTSEL = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_1015);
     String actBRSCTRL_GTSEL = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_1016);
     if((actBRSCTRL_GTSEL.compareTo(rstBRSCTRL_GTSEL) != 0) && (actBRSCTRL_GTSEL.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1017);
    stringBuffer.append(actBRSCTRL_GTSEL);
    stringBuffer.append(TEXT_1018);
     } 
    stringBuffer.append(TEXT_1019);
     VadcSfruri =  VadcBaseuri + 0 + "/backgnd" + "/globevnp_sev0np";
    stringBuffer.append(TEXT_1020);
     String rstGLOBEVNP_SEV0NP = app.getResetValue(VadcSfruri);
    stringBuffer.append(TEXT_1021);
     String actGLOBEVNP_SEV0NP = app.getMuxValue(VadcSfruri);
    stringBuffer.append(TEXT_1022);
     if((actGLOBEVNP_SEV0NP.compareTo(rstGLOBEVNP_SEV0NP) != 0) && (actGLOBEVNP_SEV0NP.compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1023);
    stringBuffer.append(actGLOBEVNP_SEV0NP);
    stringBuffer.append(TEXT_1024);
     } 
    stringBuffer.append(TEXT_1025);
     } 
    stringBuffer.append(TEXT_1026);
     //********* VADC CONFIGURATIONS ---  END ************************* 
    stringBuffer.append(TEXT_1027);
     //********* DAC CONFIGURATIONS ---  BEGIN ************************* 
    stringBuffer.append(TEXT_1028);
     if (MyObj.toString().equals("peripheral/dac")) { 
    stringBuffer.append(TEXT_1029);
      String uriDAC = null;
        for (int sliceNr=0; sliceNr<=1; sliceNr++) {
        uriDAC = "peripheral/dac/0/slice/" + sliceNr + "/cfg1_trigsel";           
        if((app.getMuxValue(uriDAC).compareTo(app.getResetValue(uriDAC)) != 0) && (app.getMuxValue(uriDAC).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1030);
    stringBuffer.append( sliceNr);
    stringBuffer.append(TEXT_1031);
    stringBuffer.append( sliceNr);
    stringBuffer.append(TEXT_1032);
    stringBuffer.append( sliceNr);
    stringBuffer.append(TEXT_1033);
    stringBuffer.append( app.getMuxValue(uriDAC) );
    stringBuffer.append(TEXT_1034);
    stringBuffer.append( sliceNr);
    stringBuffer.append(TEXT_1035);
     } 
        }
     } // if dac loop 
    stringBuffer.append(TEXT_1036);
     //********* DAC CONFIGURATIONS ---  END ************************* 
    stringBuffer.append(TEXT_1037);
    if (xmc4Device==1){
     //********* SCU CONFIGURATIONS ---  BEGIN ************************* 
    stringBuffer.append(TEXT_1038);
     if (MyObj.toString().equals("peripheral/scu")) { 
    stringBuffer.append(TEXT_1039);
      String uriSCU = null;
           uriSCU = "peripheral/scu/0/hcu/hdcr_gpi0sel";           
        if((app.getMuxValue(uriSCU).compareTo(app.getResetValue(uriSCU)) != 0) && (app.getMuxValue(uriSCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1040);
    stringBuffer.append( app.getMuxValue(uriSCU) );
    stringBuffer.append(TEXT_1041);
     } 
        uriSCU = "peripheral/scu/0/hcu/hdcr_wkupsel";           
        if((app.getMuxValue(uriSCU).compareTo(app.getResetValue(uriSCU)) != 0) && (app.getMuxValue(uriSCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1042);
    stringBuffer.append( app.getMuxValue(uriSCU) );
    stringBuffer.append(TEXT_1043);
     }  
        for (int hibpadNr=0; hibpadNr<=1; hibpadNr++) { 
          uriSCU = "port/hcu_port/0/pad/" + hibpadNr + "/hdcr_hibioxsel_oe";           
          if((app.getMuxValue(uriSCU).compareTo(app.getResetValue(uriSCU)) != 0) && (app.getMuxValue(uriSCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1044);
    stringBuffer.append( hibpadNr);
    stringBuffer.append(TEXT_1045);
    stringBuffer.append( hibpadNr);
    stringBuffer.append(TEXT_1046);
    stringBuffer.append( app.getMuxValue(uriSCU) );
    stringBuffer.append(TEXT_1047);
    stringBuffer.append( hibpadNr);
    stringBuffer.append(TEXT_1048);
     } 
          uriSCU = "port/hcu_port/0/pad/" + hibpadNr + "/hdcr_hibioxsel_pcr";           
          if((app.getMuxValue(uriSCU).compareTo(app.getResetValue(uriSCU)) != 0) && (app.getMuxValue(uriSCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1049);
    stringBuffer.append( hibpadNr);
    stringBuffer.append(TEXT_1050);
    stringBuffer.append( hibpadNr);
    stringBuffer.append(TEXT_1051);
    stringBuffer.append( app.getMuxValue(uriSCU) );
    stringBuffer.append(TEXT_1052);
    stringBuffer.append( hibpadNr);
    stringBuffer.append(TEXT_1053);
     } 
        } // hibpadNr loop         
        uriSCU = "peripheral/scu/0/gcu/interrupt/prewarn/nmireqen_prwarn";           
        if((app.getMuxValue(uriSCU).compareTo(app.getResetValue(uriSCU)) != 0) && (app.getMuxValue(uriSCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1054);
    stringBuffer.append( app.getMuxValue(uriSCU) );
    stringBuffer.append(TEXT_1055);
     }
        uriSCU = "peripheral/scu/0/gcu/interrupt/rtctick/nmireqen_pi";           
        if((app.getMuxValue(uriSCU).compareTo(app.getResetValue(uriSCU)) != 0) && (app.getMuxValue(uriSCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1056);
    stringBuffer.append( app.getMuxValue(uriSCU) );
    stringBuffer.append(TEXT_1057);
     } 
        uriSCU = "peripheral/scu/0/gcu/interrupt/rtcalarm/nmireqen_ai";           
        if((app.getMuxValue(uriSCU).compareTo(app.getResetValue(uriSCU)) != 0) && (app.getMuxValue(uriSCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1058);
    stringBuffer.append( app.getMuxValue(uriSCU) );
    stringBuffer.append(TEXT_1059);
     }
		for (int nmiEruNr=0; nmiEruNr<=3; nmiEruNr++) {
			uriSCU = "peripheral/scu/0/gcu/interrupt/nmireqen_eru0" + nmiEruNr;           
			if((app.getMuxValue(uriSCU).compareTo(app.getResetValue(uriSCU)) != 0) && (app.getMuxValue(uriSCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1060);
    stringBuffer.append( nmiEruNr);
    stringBuffer.append(TEXT_1061);
    stringBuffer.append( nmiEruNr);
    stringBuffer.append(TEXT_1062);
    stringBuffer.append( app.getMuxValue(uriSCU) );
    stringBuffer.append(TEXT_1063);
    stringBuffer.append( nmiEruNr);
    stringBuffer.append(TEXT_1064);
     }
		} // nmiEruNr loop
     } // if scu loop 
    stringBuffer.append(TEXT_1065);
     //********* SCU CONFIGURATIONS ---  END ************************* 
    } 
    if (xmc1Device==1){
     //********* SCU CONFIGURATIONS ---  BEGIN ************************* 
    stringBuffer.append(TEXT_1066);
     if (MyObj.toString().equals("peripheral/scu")) {  
    stringBuffer.append(TEXT_1067);
      String uriSCU_CCU = null;
                uriSCU_CCU = "peripheral/scu/0/ccu/config/clkcr_rtcclksel";
                if((app.getMuxValue(uriSCU_CCU).compareTo(app.getResetValue(uriSCU_CCU)) != 0) && (app.getMuxValue(uriSCU_CCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1068);
    stringBuffer.append( app.getMuxValue(uriSCU_CCU) );
    stringBuffer.append(TEXT_1069);
     } 
      		  String uriSCU_CMPCU = null;
                uriSCU_CMPCU = "peripheral/scu/0/cmpcu/anacmp/0/acmp_sel";
                if((app.getMuxValue(uriSCU_CMPCU).compareTo(app.getResetValue(uriSCU_CMPCU)) != 0) && (app.getMuxValue(uriSCU_CMPCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1070);
    stringBuffer.append( app.getMuxValue(uriSCU_CMPCU) );
    stringBuffer.append(TEXT_1071);
     }
                uriSCU_CMPCU = "peripheral/scu/0/cmpcu/anacmp/1/ref_div_en";
                if((app.getMuxValue(uriSCU_CMPCU).compareTo(app.getResetValue(uriSCU_CMPCU)) != 0) && (app.getMuxValue(uriSCU_CMPCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1072);
    stringBuffer.append( app.getMuxValue(uriSCU_CMPCU) );
    stringBuffer.append(TEXT_1073);
     }
                uriSCU_CMPCU = "peripheral/scu/0/cmpcu/anacmp/2/acmp_sel";
                if((app.getMuxValue(uriSCU_CMPCU).compareTo(app.getResetValue(uriSCU_CMPCU)) != 0) && (app.getMuxValue(uriSCU_CMPCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1074);
    stringBuffer.append( app.getMuxValue(uriSCU_CMPCU) );
    stringBuffer.append(TEXT_1075);
     }
     } // if loop 
     //********* SCU CONFIGURATIONS ---  END ************************* 
     //********* LEDTS CONFIGURATIONS ---  BEGIN ************************* 
    stringBuffer.append(TEXT_1076);
     if (MyObj.toString().equals("peripheral/ledts")) {  
    stringBuffer.append(TEXT_1077);
      String uriLEDTS = null;
               uriLEDTS = "peripheral/ledts/1/global/globctl_ensync";
               if((app.getMuxValue(uriLEDTS).compareTo(app.getResetValue(uriLEDTS)) != 0) && (app.getMuxValue(uriLEDTS).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1078);
    stringBuffer.append( app.getMuxValue(uriLEDTS) );
    stringBuffer.append(TEXT_1079);
     }
     } // if loop 
     //********* LEDTS-1 CONFIGURATIONS ---  END ************************* 
     //********* BCCU CONFIGURATIONS ---  BEGIN ************************* 
    stringBuffer.append(TEXT_1080);
     if (MyObj.toString().equals("peripheral/bccu")) {  
    stringBuffer.append(TEXT_1081);
      String uriBCCU = null;
               for (int chNr=0; chNr<=8; chNr++) {
                uriBCCU = "peripheral/bccu/0/channel/" + chNr + "/chconfig_dsel";
                if((app.getMuxValue(uriBCCU).compareTo(app.getResetValue(uriBCCU)) != 0) && (app.getMuxValue(uriBCCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1082);
    stringBuffer.append( chNr);
    stringBuffer.append(TEXT_1083);
    stringBuffer.append( app.getMuxValue(uriBCCU) );
    stringBuffer.append(TEXT_1084);
    stringBuffer.append( chNr);
    stringBuffer.append(TEXT_1085);
     } // if statement.
           } // chNr loop.
                uriBCCU = "peripheral/bccu/0/trap/globcon_trapis";
                if((app.getMuxValue(uriBCCU).compareTo(app.getResetValue(uriBCCU)) != 0) && (app.getMuxValue(uriBCCU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1086);
    stringBuffer.append( app.getMuxValue(uriBCCU) );
    stringBuffer.append(TEXT_1087);
     } // if statement.
     } // if loop 
     //********* BCCU CONFIGURATIONS ---  END ************************* 
    } 
     //********* ERU CONFIGURATIONS ---  BEGIN ************************* 
    stringBuffer.append(TEXT_1088);
     if (MyObj.toString().equals("peripheral/eru")) {  
      String uriERU = null;
           for (int eruNr=0; eruNr<=1; eruNr++) { 
    stringBuffer.append(TEXT_1089);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1090);
     for (int ersNr=0; ersNr<=3; ersNr++) {
                uriERU = "peripheral/eru/" + eruNr + "/ers_etl/" + ersNr + "/exisel_exsxa";
                if((app.getMuxValue(uriERU).compareTo(app.getResetValue(uriERU)) != 0) && (app.getMuxValue(uriERU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1091);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1092);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1093);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1094);
    stringBuffer.append( app.getMuxValue(uriERU) );
    stringBuffer.append(TEXT_1095);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1096);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1097);
     } 
                uriERU = "peripheral/eru/" + eruNr + "/ers_etl/" + ersNr + "/exisel_exsxb";
                if((app.getMuxValue(uriERU).compareTo(app.getResetValue(uriERU)) != 0) && (app.getMuxValue(uriERU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1098);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1099);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1100);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1101);
    stringBuffer.append( app.getMuxValue(uriERU) );
    stringBuffer.append(TEXT_1102);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1103);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1104);
     }
                uriERU = "peripheral/eru/" + eruNr + "/ers_etl/" + ersNr + "/exicon_pe";
                if((app.getMuxValue(uriERU).compareTo(app.getResetValue(uriERU)) != 0) && (app.getMuxValue(uriERU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1105);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1106);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1107);
    stringBuffer.append( app.getMuxValue(uriERU) );
    stringBuffer.append(TEXT_1108);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1109);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1110);
     }
                uriERU = "peripheral/eru/" + eruNr + "/ers_etl/" + ersNr + "/exicon_ocs";
                if((app.getMuxValue(uriERU).compareTo(app.getResetValue(uriERU)) != 0) && (app.getMuxValue(uriERU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1111);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1112);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1113);
    stringBuffer.append( app.getMuxValue(uriERU) );
    stringBuffer.append(TEXT_1114);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1115);
    stringBuffer.append( ersNr);
    stringBuffer.append(TEXT_1116);
     } 
            } // ersNr loop 
            for (int oguNr=0; oguNr<=3; oguNr++) {
                for (int ipenNr=0; ipenNr<=3; ipenNr++) {
                    uriERU = "peripheral/eru/" + eruNr + "/ogu/" + oguNr + "/exocon_ipen" + ipenNr;
                    if((app.getMuxValue(uriERU).compareTo(app.getResetValue(uriERU)) != 0) && (app.getMuxValue(uriERU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1117);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1118);
    stringBuffer.append( oguNr);
    stringBuffer.append(TEXT_1119);
    stringBuffer.append( ipenNr);
    stringBuffer.append(TEXT_1120);
    stringBuffer.append( ipenNr);
    stringBuffer.append(TEXT_1121);
    stringBuffer.append( app.getMuxValue(uriERU) );
    stringBuffer.append(TEXT_1122);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1123);
    stringBuffer.append( oguNr);
    stringBuffer.append(TEXT_1124);
    stringBuffer.append( ipenNr);
    stringBuffer.append(TEXT_1125);
     }
                } // ipen loop
                uriERU = "peripheral/eru/" + eruNr + "/ogu/" + oguNr + "/exocon_iss";
                if((app.getMuxValue(uriERU).compareTo(app.getResetValue(uriERU)) != 0) && (app.getMuxValue(uriERU).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1126);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1127);
    stringBuffer.append( oguNr);
    stringBuffer.append(TEXT_1128);
    stringBuffer.append( app.getMuxValue(uriERU) );
    stringBuffer.append(TEXT_1129);
    stringBuffer.append( eruNr);
    stringBuffer.append(TEXT_1130);
    stringBuffer.append( oguNr);
    stringBuffer.append(TEXT_1131);
     } 
            } // oguNr loop            
        } // eruNr loop
     } // if eru loop 
     //********* ERU CONFIGURATIONS ---  END ************************* 
     //********* PORT CONFIGURATIONS ---  BEGIN ************************* 
     if (MyObj.toString().equals("port/p")) { 
    stringBuffer.append(TEXT_1132);
      String uriPORT = null;
        int firstPadNr = 0;
        int lastPadNr = 15;
        int iomode = 0;
        for (int portNr=0; portNr<=15; portNr++) {     
            if (portNr==4) {lastPadNr = 7;}
            if (portNr==5) {lastPadNr = 11;}
            if (portNr==6) {lastPadNr = 6;}
            if (portNr==15) {firstPadNr = 2;}
            if ((portNr<=6) | (portNr==14)| (portNr==15)) {
               for (int padNr=firstPadNr; padNr<=lastPadNr; padNr++) { 
                   if (!(((portNr==14) | (portNr==15)) & ((padNr==10)|(padNr==11)))) { 
                       uriPORT = "port/p/" + portNr + "/pad/" + padNr + "/iocr_oe";
                       if((app.getMuxValue(uriPORT).compareTo(app.getResetValue(uriPORT)) != 0) && (app.getMuxValue(uriPORT).compareTo("") != 0)) {
                       iomode = Integer.parseInt(app.getMuxValue(uriPORT));
                       }
					   if (iomode == 1) {
                       uriPORT = "port/p/" + portNr + "/pad/" + padNr + "/pdisc_pdis";
                       if((app.getMuxValue(uriPORT).compareTo(app.getResetValue(uriPORT)) != 0) && (app.getMuxValue(uriPORT).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1133);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1134);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1135);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1136);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1137);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1138);
    stringBuffer.append( app.getMuxValue(uriPORT) );
    stringBuffer.append(TEXT_1139);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1140);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1141);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1142);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1143);
     }					   
					   uriPORT = "port/p/" + portNr + "/pad/" + padNr + "/hwsel_hw";
                       if((app.getMuxValue(uriPORT).compareTo(app.getResetValue(uriPORT)) != 0) && (app.getMuxValue(uriPORT).compareTo("") != 0)) { 
                       int hwsel = Integer.parseInt(app.getMuxValue(uriPORT)); if (hwsel > 0) { hwsel = hwsel - 1; 
    stringBuffer.append(TEXT_1144);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1145);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1146);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1147);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1148);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1149);
    stringBuffer.append( hwsel );
    stringBuffer.append(TEXT_1150);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1151);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1152);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1153);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1154);
     } else if (hwsel == 0) { 
    stringBuffer.append(TEXT_1155);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1156);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1157);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1158);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1159);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1160);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1161);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1162);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1163);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1164);
     } }
                       uriPORT = "port/p/" + portNr + "/pad/" + padNr + "/iocr_pcr";
                       if((app.getMuxValue(uriPORT).compareTo(app.getResetValue(uriPORT)) != 0) && (app.getMuxValue(uriPORT).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1165);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1166);
    stringBuffer.append( ((padNr / 4) * 4));
    stringBuffer.append(TEXT_1167);
    stringBuffer.append( padNr - ((padNr / 4) * 4));
    stringBuffer.append(TEXT_1168);
    stringBuffer.append( padNr - ((padNr / 4) * 4));
    stringBuffer.append(TEXT_1169);
    stringBuffer.append( app.getMuxValue(uriPORT) );
    stringBuffer.append(TEXT_1170);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1171);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1172);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1173);
    stringBuffer.append( ((padNr / 4) * 4));
    stringBuffer.append(TEXT_1174);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1175);
     }
                       uriPORT = "port/p/" + portNr + "/pad/" + padNr + "/iocr_oe";
                       if((app.getMuxValue(uriPORT).compareTo(app.getResetValue(uriPORT)) != 0) && (app.getMuxValue(uriPORT).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1176);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1177);
    stringBuffer.append( ((padNr / 4) * 4));
    stringBuffer.append(TEXT_1178);
    stringBuffer.append( padNr - ((padNr / 4) * 4));
    stringBuffer.append(TEXT_1179);
    stringBuffer.append( padNr - ((padNr / 4) * 4));
    stringBuffer.append(TEXT_1180);
    stringBuffer.append( app.getMuxValue(uriPORT) );
    stringBuffer.append(TEXT_1181);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1182);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1183);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1184);
    stringBuffer.append( ((padNr / 4) * 4));
    stringBuffer.append(TEXT_1185);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1186);
     }
					   iomode = 0; }
                    } // if portNr(14,15)& padNr(14,15) loop     
                } // padNr loop
            } // if portNr(6,14,15) loop 
            firstPadNr = 0; lastPadNr = 15;
        } // portNr loop     
    } // if port loop 
    stringBuffer.append(TEXT_1187);
     //********* PORT CONFIGURATIONS ---  END ************************* 
     } 
    stringBuffer.append(TEXT_1188);
     
   String MyTempPeriName1 = null;
   Object MyObj1 = null; 	
   Set set1 = PeriHashMap.entrySet(); 
   Iterator i1 = set.iterator();
     while(i1.hasNext()) { 
     Map.Entry peri_me1 = (Map.Entry)i1.next();  
           MyObj1 = peri_me1.getKey();              
           MyTempPeriName1 = MyObj1.toString(); 

   //********* PORT CONFIGURATIONS ---  BEGIN *************************
      if (MyObj1.toString().equals("port/p")) { 
    stringBuffer.append(TEXT_1189);
      String uriPORT1 = null;
        int firstPadNr1 = 0;
        int lastPadNr1 = 15;
        int iomode1 = 0;
        for (int portNr=0; portNr<=15; portNr++) {     
            if (portNr==4) {lastPadNr1 = 7;}
            if (portNr==5) {lastPadNr1 = 11;}
            if (portNr==6) {lastPadNr1 = 6;}
            if (portNr==15) {firstPadNr1 = 2;}
            if ((portNr<=6) | (portNr==14)| (portNr==15)) {
               for (int padNr=firstPadNr1; padNr<=lastPadNr1; padNr++) { 
                   if (!(((portNr==14) | (portNr==15)) & ((padNr==10)|(padNr==11)))) { 
                       uriPORT1 = "port/p/" + portNr + "/pad/" + padNr + "/iocr_oe";
                       if((app.getMuxValue(uriPORT1).compareTo(app.getResetValue(uriPORT1)) != 0) && (app.getMuxValue(uriPORT1).compareTo("") != 0)) {
                       iomode1 = Integer.parseInt(app.getMuxValue(uriPORT1));
                       } 
					   if (iomode1 == 0) {
                       uriPORT1 = "port/p/" + portNr + "/pad/" + padNr + "/pdisc_pdis";
                       if((app.getMuxValue(uriPORT1).compareTo(app.getResetValue(uriPORT1)) != 0) && (app.getMuxValue(uriPORT1).compareTo("") != 0)) { 
    stringBuffer.append(TEXT_1190);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1191);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1192);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1193);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1194);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1195);
    stringBuffer.append( app.getMuxValue(uriPORT1) );
    stringBuffer.append(TEXT_1196);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1197);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1198);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1199);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1200);
     }
					   uriPORT1 = "port/p/" + portNr + "/pad/" + padNr + "/hwsel_hw";
                       if((app.getMuxValue(uriPORT1).compareTo(app.getResetValue(uriPORT1)) != 0) && (app.getMuxValue(uriPORT1).compareTo("") != 0)) { 
                       int hwsel1 = Integer.parseInt(app.getMuxValue(uriPORT1)); if (hwsel1 > 0) { hwsel1 = hwsel1 - 1; 
    stringBuffer.append(TEXT_1201);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1202);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1203);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1204);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1205);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1206);
    stringBuffer.append( hwsel1 );
    stringBuffer.append(TEXT_1207);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1208);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1209);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1210);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1211);
     } else if (hwsel1 == 0) { 
    stringBuffer.append(TEXT_1212);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1213);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1214);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1215);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1216);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1217);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1218);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1219);
    stringBuffer.append( portNr);
    stringBuffer.append(TEXT_1220);
    stringBuffer.append( padNr);
    stringBuffer.append(TEXT_1221);
     } }					   
                       } else { iomode1 = 0; }
                    } // if portNr(14,15)& padNr(14,15) loop     
                } // padNr loop
            } // if portNr(6,14,15) loop 
            firstPadNr1 = 0; lastPadNr1 = 15;
        } // portNr loop     
    } // if port loop 
    stringBuffer.append(TEXT_1222);
     //********* PORT CONFIGURATIONS ---  END ************************* 
     } 
    stringBuffer.append(TEXT_1223);
    stringBuffer.append(TEXT_1224);
    return stringBuffer.toString();
  }
}
