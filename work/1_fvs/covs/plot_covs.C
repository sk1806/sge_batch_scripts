// Bin1 = det1, flavour1(numu), bin1
// Bin2 = det1, flavour1(numu), bin2
// ...
// Bin x = det1, flavour2(numubar), bin1
// Bin y = det1, flavour2(numubar), bin2
// ... 
// ...
// Bin z = det2, flavour1(numu), bin1

// Each det has 20*4=80 bins per horn polarity

// skfhc, skrhc, hk2fhc, hk2rhc, nd280baskfhc, nd280baskrhc, IWCD

// note - cov bins labeled from 0-(N-1)
//      - histo bins labeled from 1-N


// Remiding myself of the obvious...
// bin = 0;       underflow bin
// bin = 1;       first bin with low-edge xlow INCLUDED
// bin = nbins;   last bin with upper-edge xup EXCLUDED
// bin = nbins+1; overflow bin

#include <cov_tools.c>

int plot_covs(){	

  // --- XXX --- THINGS TO EDIT --- XXX --- ///
	

  std::string tag = "./1_fvs__sk_nd5_nd2_nd9h7p7_hk2_hk3_hkk4_hhk5";
  const int ndets = (1+1+1+7 + 4)*2 ;


//  TFile* TFcov = new TFile("./1_fvs__sk_hk2_nd5_nd9h10__prod_xsec_cov.root");
//  TMatrixTSym<double>* matT = (TMatrixTSym<double>*) TFcov->Get("prod_xsec_cov");

  //TFile* TFcov = new TFile("./1_fvs__sk_nd5_nd2_nd9h7p7_hk2_hk3_hkk4_hhk5_prodx_cov.root");
  //TMatrixTSym<double>* matT = (TMatrixTSym<double>*) TFcov->Get("prodx_cov");

//  TFile* TFcov = new TFile("./offAxis_Benjamin__sk_nd5_hkToch_hkHak_hkkBis_hhkBoh_oaax_cov.root");
//  TMatrixTSym<double>* matT = (TMatrixTSym<double>*) TFcov->Get("oaax_cov");

  //const int ndets = ( 6 )*2 ;


  bool alttert   = true;
  bool bmpt      = false;
  bool harp      = false;
  bool na61      = false;
  bool oaax      = false;
  bool oaay      = false;
  bool pbeamx    = false;
  bool pbeamy    = false;
  bool prodx     = false;
  bool snextbar  = false;
  bool snleadbar = false;
  bool snmult    = false;



  // --- XXX ---------------------- XXX--- ///		
 


  const int nflavours = 4;
  const int nbins = 20;
  const int nBinsPerDet = nbins*nflavours;

  bool setMin = false;   const int binMin = 0;
  bool setMax = false;   const int binMax = 0;
  const int binOffset = 0;
  
  const int nRow =  nflavours* nbins * ndets ;
  std::cout<<" nRow = " << nRow << std::endl;



  if( alttert  ) std::string str_syst = "alttert";
  if( bmpt     ) std::string str_syst = "bmpt";
  if( harp     ) std::string str_syst = "harp";
  if( na61     ) std::string str_syst = "na61";
  if( oaax     ) std::string str_syst = "oaax";
  if( oaay     ) std::string str_syst = "oaay";
  if( pbeamx   ) std::string str_syst = "pbeamx";
  if( pbeamy   ) std::string str_syst = "pbeamy";
  if( prodx    ) std::string str_syst = "prodx";
  if( snextbar ) std::string str_syst = "snextbar";
  if( snleadbar) std::string str_syst = "snleadbar";
  if( snmult   ) std::string str_syst = "snmult";
  
  std::string str_rootFile = tag +"_"+ str_syst +"_cov.root";
  std::string str_cov = str_syst +"_cov";

  const char* ch_rootFile = str_rootFile.c_str();
  const char* ch_cov = str_cov.c_str();

  TFile* TFcov = new TFile( ch_rootFile );
  TMatrixTSym<double>* matT = (TMatrixTSym<double>*) TFcov->Get( ch_cov );

 
  const int det_1_lowBin=1;      const int det_1_highBin=80;  //     numu=1-20, anumu=21-40, nue=41-60, anue=61-80
  const int det_2_lowBin=81;     const int det_2_highBin=160;  //    numu=81-100, anumu=101-120, nue=121-140, anue=141-160
  const int det_3_lowBin=161;    const int det_3_highBin=240;  //    numu=161-180, anumu=181-200, nue=201-220, anue=221-240
  const int det_4_lowBin=241;    const int det_4_highBin=320;  //    numu=241-260, anumu=261-280, nue=281-300, anue=301-320
  const int det_5_lowBin=321;    const int det_5_highBin=400;  //    numu=321-340, anumu=341-360, nue=361-380, anue=381-400
  const int det_6_lowBin=401;    const int det_6_highBin=480;  //    numu=401-420, anumu=421-440, nue=441-460, anue=461-480
  const int det_7_lowBin=481;    const int det_7_highBin=560;  //    numu=481-500, anumu=501-520, nue=521-540, anue=541-560
  const int det_8_lowBin=561;    const int det_8_highBin=640;  //    numu=561-580, anumu=581-600, nue=601-620, anue=621-640
  const int det_9_lowBin=641;    const int det_9_highBin=720;  //    numu=641-660, anumu=661-680, nue=681-700, anue=701-720
  const int det_10_lowBin=721;   const int det_10_highBin=800;  //   numu=721-740, anumu=741-760, nue=761-780, anue=781-800
  const int det_11_lowBin=801;   const int det_11_highBin=880;  //   numu=801-820, anumu=821-840, nue=841-860, anue=861-880
  const int det_12_lowBin=881;   const int det_12_highBin=960;  //   numu=881-900, anumu=901-920, nue=921-940, anue=941-960
  const int det_13_lowBin=961;   const int det_13_highBin=1040;  //  numu=961-980, anumu=981-1000, nue=1001-1020, anue=1021-1040
  const int det_14_lowBin=1041;  const int det_14_highBin=1120;  //  numu=1041-1060, anumu=1061-1080, nue=1081-1100, anue=1101-1120
  const int det_15_lowBin=1121;  const int det_15_highBin=1200;  //  numu=1121-1140, anumu=1141-1160, nue=1161-1180, anue=1181-1200
  const int det_16_lowBin=1201;  const int det_16_highBin=1280;  //  numu=1201-1220, anumu=1221-1240, nue=1241-1260, anue=1261-1280
  const int det_17_lowBin=1281;  const int det_17_highBin=1360;  //  numu=1281-1300, anumu=1301-1320, nue=1321-1340, anue=1341-1360
  const int det_18_lowBin=1361;  const int det_18_highBin=1440;  //  numu=1361-1380, anumu=1381-1400, nue=1401-1420, anue=1421-1440
  const int det_19_lowBin=1441;  const int det_19_highBin=1520;  //  numu=1441-1460, anumu=1461-1480, nue=1481-1500, anue=1501-1520
  const int det_20_lowBin=1521;  const int det_20_highBin=1600;  //  numu=1521-1540, anumu=1541-1560, nue=1561-1580, anue=1581-1600
  const int det_21_lowBin=1601;  const int det_21_highBin=1680;  //  numu=1601-1620, anumu=1621-1640, nue=1641-1660, anue=1661-1680
  const int det_22_lowBin=1681;  const int det_22_highBin=1760;  //  numu=1681-1700, anumu=1701-1720, nue=1721-1740, anue=1741-1760
  const int det_23_lowBin=1761;  const int det_23_highBin=1840;  //  numu=1761-1780, anumu=1781-1800, nue=1801-1820, anue=1821-1840
  const int det_24_lowBin=1841;  const int det_24_highBin=1920;  //  numu=1841-1860, anumu=1861-1880, nue=1881-1900, anue=1901-1920
  const int det_25_lowBin=1921;  const int det_25_highBin=2000;  //  numu=1921-1940, anumu=1941-1960, nue=1961-1980, anue=1981-2000
  const int det_26_lowBin=2001;  const int det_26_highBin=2080;  //  numu=2001-2020, anumu=2021-2040, nue=2041-2060, anue=2061-2080
  const int det_27_lowBin=2081;  const int det_27_highBin=2160;  //  numu=2081-2100, anumu=2101-2120, nue=2121-2140, anue=2141-2160
  const int det_28_lowBin=2161;  const int det_28_highBin=2240;  //  numu=2161-2180, anumu=2181-2200, nue=2201-2220, anue=2221-2240
  const int det_29_lowBin=2241;  const int det_29_highBin=2320;  //  numu=2241-2260, anumu=2261-2280, nue=2281-2300, anue=2301-2320
  const int det_30_lowBin=2321;  const int det_30_highBin=2400;  //  numu=2321-2340, anumu=2341-2360, nue=2361-2380, anue=2381-2400
  
  




  ////////////////////////////////////////////////////////////////////////
  ///////////////// Retrieving and plotting the full cov /////////////////


  ////// Turn TMatrixTSym cov matrix into TH2D cov matrix //////


  //  TH2D* h = new TMatrixTSym_to_TH2D(matT, nRow, 0 );
  TH2D* h_cov = new TH2D("h", "h", nRow, 0, nRow, nRow, 0, nRow);


  // Takes a matrix of type TMatrixDSym and transform it into a TH2D histogram
  // - elemet 0 of TMatrixDSym corresponds to Bin(1,1) of the TH2D
  TMatrixTSym_to_TH2D(*matT, nRow, 0, *h_cov );

  std::cout<<" nRow = " << nRow << std::endl;

  double min_mac = 9999;  int minRow_mac = 9999;
  double max_mac = -9999; int maxRow_mac = -9999;
  for( int i=0; i< nRow; i++){
    double e = h_cov->GetBinContent(i+1, i+1)  ;
    //std::cout<<" h_cov->GetBinContent("<< i+1 <<","<< i+1 <<") = " << e  << std::endl; 
    std::cout<<" sig = " << sqrt(e) << std::endl;
    if(e<min_mac){ min_mac = e; minRow_mac=i+1;}
    if(e>max_mac){ max_mac = e; maxRow_mac=i+1;}
  }

  std::cout<<" "<<std::endl;
  std::cout<<" Largest error (sqrt cov diag) "<<std::endl;
  std::cout<<" "<<std::endl;
  std::cout<<" -> Where first bin is numbered from 1"<<std::endl;
  std::cout<<" "<<std::endl;
  std::cout<<" Inside plot_covs:   min = "<< min_mac << ", sig = "<< sqrt(min_mac) << ":    minRow = " << minRow_mac << std::endl;
  std::cout<<" Inside plot_covs:   max = "<< max_mac << ", sig = "<< sqrt(max_mac) << ":      maxRow = " << maxRow_mac << std::endl;
  std::cout<<" " << std::endl;


  std::cout<<" " << std::endl;
  std::cout<<" ----------------------------" << std::endl;
  std::cout<<"Checking for errors over 15%  " << std::endl;

  for( int i=0; i< nRow; i++){
    double e = h_cov->GetBinContent(i+1, i+1)  ;
    //std::cout<<" sig = " << sqrt(e) << std::endl;
    if( sqrt(e) > 0.15 ) std::cout<<"  Sig = "<< sqrt(e) <<",  Row = " << i+1 << std::endl;
  }
  std::cout<<" " << std::endl;
  std::cout<<" " << std::endl;
  std::cout<<" ----------------------------" << std::endl;


  std::cout<<""<<std::endl;
  std::cout<<" Check the TH2D has filled from the TMatrixTStm correctly"<<std::endl;
  double matT_00 = (*matT)[0][0]; 
  std::cout<<" TMatrixTSym:                      matT[0][0] = " << matT_00 << std::endl;
  std::cout<<" TH2D:         h_cov->GetBinContent(0+1, 0+1) = "<< h_cov->GetBinContent(0+1, 0+1)  << std::endl;


  // Can readout min/max numbers of the covariance Th2D hist
  std::cout<<""<<std::endl;
  std::cout<<" Finding min/max element of covariance matrix to readout " << std::endl;
  readOutMinMax_TH2D( *h_cov, nRow, nRow );
//
//
  // Can save and readout min/max numbers of the covariance Th2D hist
  std::cout<<""<<std::endl;
  std::cout<<" Finding min/max element of covariance matrix to save" << std::endl;
  double min = 9999.0;  int minRow = -9999; int minCol = -9999;
  double max = -9999.0; int maxRow = -9999; int maxCol = -9999;
  returnMinMax_TH2D( *h_cov , nRow, nRow, min, minRow, minCol, max, maxRow, maxCol, true );
  std::cout<<"Min bin:  ("<< minRow <<", "<< minCol <<") = " << min << std::endl;
  std::cout<<"Max bin:  ("<< maxRow <<", "<< maxCol <<") = " << max << std::endl;




  
  // sanity checks

  std::cout<<""<<std::endl;
  std::cout<<"  Perform sanity check " << std::endl;
  std::cout<<""<<std::endl;

  std::cout<<""<<std::endl;
  double matT_00 = (*matT)[ 0 ][ 0 ];
  double h_cov_11 = h_cov->GetBinContent( 0+1, 0+1 ); 
  std::cout<<""<<std::endl;
  std::cout<<" From Matrix,  (*matT)[ 0 ][ 0 ]                 =  cov(0,0) = " << matT_00 << std::endl;
  std::cout<<" From 2d hist, h_cov->GetBinContent( 0+1, 0+1 ); =  cov(0,0) = " << h_cov_11 << std::endl;
  std::cout<<""<<std::endl;

  std::cout<<""<<std::endl;
  double matT_23 = (*matT)[ 2 ][ 3 ];
  double h_cov_34 = h_cov->GetBinContent( 2+1, 3+1 ); 
  std::cout<<""<<std::endl;
  std::cout<<" From Matrix,  (*matT)[ 2 ][ 3 ]                 =  cov(2,3) = " << matT_23 << std::endl;
  std::cout<<" From 2d hist, h_cov->GetBinContent( 2+1, 2+1 ); =  cov(2,3) = " << h_cov_34 << std::endl;
  std::cout<<""<<std::endl;

  std::cout<<""<<std::endl;
  double sig_00 = sqrt( h_cov->GetBinContent( 0+1, 0+1 ) );
  std::cout<<" sig_00  = sqrt( cov(0,0) ) = "<< sig_00 <<std::endl;
  double sig_11 = sqrt( h_cov->GetBinContent( 1+1, 1+1 ) );
  std::cout<<" sig_11  = sqrt( cov(1,1) ) = "<< sig_11 <<std::endl;
  double sig_22 = sqrt( h_cov->GetBinContent( 2+1, 2+1 ) );
  std::cout<<" sig_22  = sqrt( cov(2,2) ) = "<< sig_22 <<std::endl;
  std::cout<<""<<std::endl;


//  
//
//  // Plot cov - large canvas  
//  plot_TH2D_cov_default_colz_large( *h_cov, "prod_xsec", "", "Production xs syst"  );
//  // Plot cov - small canvas
//  plot_TH2D_cov_default_colz_small( *h_cov, "prod_xsec", "", "Production xs syst"  );


// XXX --------------------------------------------------------------------------- XXX //
// XXX weird behaviour where you call pointer to array after any unrelated loop !? XXX //
//  double* var;
//  var = extractArrayDaigCov_var( *h_cov, nRow);
//  std::cout<<" var[4] = " << var[4] << std::endl;
//
//  double sqrt_array_4 =  sqrt( var[4] ) ;
//  std::cout<<"  sqrt( var[4] ) " << sqrt_array_4 << std::endl; 
//
//  std::cout<<"var[4] = "<< var[4] <<std::endl;
//  for( int a=0; a<3; a++){}
//  std::cout<<"var[4] = "<< var[4] <<std::endl;
//  std::cout<<" Whaaaat " << std::endl;
//  // XXX why cant u cann pointer to array inside a loop
//  double* ptr_var;
//  ptr_var = extractArrayDaigCov_var( *h_cov, nRow);
//  std::cout<<" ptr_var[4] = " << ptr_var[4] << std::endl;
//
//  double var[nRow];
//  for( int i=0; i<nRow; i++){
//    var[i]=ptr_var[i];
//    std::cout<<" var["<< i <<"] = " << var[i] << std::endl; 
//  }
// XXX --------------------------------------------------------------------------- XXX //
 
 
   ////////////////////////////////////////////////////////////////////////
   ////////////// Build and plot the full correlations matrix  /////////////
 
  // corr_ik = cov_ik / (sig_i sig_k)  = cov_ik / sqrt(var_i var_k) = cov_ik / sqrt(cov_ii cov_kk)
  // cov_ii = var_i = (sig_i)^2
  // so uncorrelated error,  sig_i = sqrt( var(i) ) = sqrt{ cov_ii )

  // create the correlation matrix here inside macro as cross check for using the function in cov_tools
  TH2D* h_corr_mac = new TH2D("h_corr_mac", "h_corr_mac", nRow, 0, nRow, nRow, 0, nRow);
  for( int irow=0; irow< nRow; irow++){

    double h_cov_ii = h_cov->GetBinContent( irow+1, irow+1 );  

    for( int icol=0; icol< nRow; icol++){
  
      double h_cov_kk = h_cov->GetBinContent( icol+1, icol+1 );
      double h_cov_ik = h_cov->GetBinContent( irow+1, icol+1 );
      double h_corr_mac_ik = h_cov_ik / sqrt( h_cov_ii * h_cov_kk );
      h_corr_mac->SetBinContent( irow+1, icol+1, h_corr_mac_ik );
    }
  }


  // create correlation matrix using the function
  TH2D* h_corr = new TH2D("h_corr", "h_corr", nRow, 0, nRow, nRow, 0, nRow);
  buildCorFromCov( *h_cov, nRow, *h_corr );

  // sanity check:  corr matrix from function is the same as corr matrix made inside this macro 
   std::cout<<""<<std::endl;
   std::cout<<" h_corr->GetBinContent(1,1) = "     <<  h_corr->GetBinContent(1,1) << std::endl;
   std::cout<<" h_corr_mac->GetBinContent(1,1) = " <<  h_corr_mac->GetBinContent(1,1) << std::endl;
   std::cout<<""<<std::endl;
   std::cout<<" h_corr->GetBinContent(1,8) = "     <<  h_corr->GetBinContent(1,8) << std::endl;
   std::cout<<" h_corr_mac->GetBinContent(1,8) = " <<  h_corr_mac->GetBinContent(1,8) << std::endl;
   std::cout<<""<<std::endl;
   std::cout<<" h_corr->GetBinContent(4,5) = "     <<  h_corr->GetBinContent(4,5) << std::endl;
   std::cout<<" h_corr_mac->GetBinContent(4,5) = " <<  h_corr_mac->GetBinContent(4,5) << std::endl;
   std::cout<<""<<std::endl;
   std::cout<<" h_corr->GetBinContent(6,6) = "     <<  h_corr->GetBinContent(6,6) << std::endl;
   std::cout<<" h_corr_mac->GetBinContent(6,6) = " <<  h_corr_mac->GetBinContent(6,6) << std::endl;
   std::cout<<""<<std::endl;
   std::cout<<""<<std::endl;







  
  ///////////////////////////////////////////////////////////////
  ///// Cut out det matrices from the full correlation matrix ////

  //TH2D* h_corr_det = new TH2D("h_corr_det", "h_corr_det", nBinsPerDet, 0, nBinsPerDet, nBinsPerDet, 0, nBinsPerDet );
  //TH2D h_corr_det = T2HD("h_corr_det", "h_corr_det", nBinsPerDet, 0, nBinsPerDet, nBinsPerDet, 0, nBinsPerDet );

  std::string str_det_1 = "1_sk_fhc";
  //int det1_corr = cutOutDet_corr(  h_corr, det_1_lowBin,  det_1_highBin,  nBinsPerDet,  str_det_1, str_syst );
  int det1_err = getErrosFromCov( h_cov,  det_1_lowBin, det_1_highBin,  nBinsPerDet,  str_det_1 , str_syst );

  std::string str_det_2 = "1_sk_rhc";
  //int det2_corr = cutOutDet_corr(  h_corr, det_2_lowBin,  det_2_highBin,  nBinsPerDet,  str_det_2, str_syst );
  int det2_err = getErrosFromCov( h_cov,  det_2_lowBin, det_2_highBin,  nBinsPerDet,  str_det_2 , str_syst );

  std::string str_det_3 = "nd5_fhc";
  //int det3_corr = cutOutDet_corr(  h_corr, det_3_lowBin,  det_3_highBin,  nBinsPerDet,  str_det_3, str_syst );
  int det3_err = getErrosFromCov( h_cov,  det_3_lowBin, det_3_highBin,  nBinsPerDet,  str_det_3 , str_syst );

  std::string str_det_4 = "nd5_rhc";
  ///int det4_corr = cutOutDet_corr(  h_corr, det_4_lowBin,  det_4_highBin,  nBinsPerDet,  str_det_4, str_syst );
  int det4_err = getErrosFromCov( h_cov,  det_4_lowBin, det_4_highBin,  nBinsPerDet,  str_det_4 , str_syst );



  std::string str_det_5 = "nd2_fhc";
  //int det5_corr = cutOutDet_corr(  h_corr, det_5_lowBin,  det_5_highBin,  nBinsPerDet,  str_det_5, str_syst );
  int det5_err = getErrosFromCov( h_cov,  det_5_lowBin, det_5_highBin,  nBinsPerDet,  str_det_5 , str_syst );

  std::string str_det_6 = "nd2_rhc";
  //int det6_corr = cutOutDet_corr(  h_corr, det_6_lowBin,  det_6_highBin,  nBinsPerDet,  str_det_6, str_syst );
  int det6_err = getErrosFromCov( h_cov,  det_6_lowBin, det_6_highBin,  nBinsPerDet,  str_det_6 , str_syst );

  std::string str_det_7 = "nd9_h7p7_1_fhc";
  //int det7_corr = cutOutDet_corr(  h_corr, det_7_lowBin,  det_7_highBin,  nBinsPerDet,  str_det_7, str_syst );
  int det7_err = getErrosFromCov( h_cov,  det_7_lowBin, det_7_highBin,  nBinsPerDet,  str_det_7 , str_syst );

  std::string str_det_8 = "nd9_h7p7_1_rhc";
  //int det8_corr = cutOutDet_corr(  h_corr, det_8_lowBin,  det_8_highBin,  nBinsPerDet,  str_det_8, str_syst );
  int det8_err = getErrosFromCov( h_cov,  det_8_lowBin, det_8_highBin,  nBinsPerDet,  str_det_8 , str_syst );

  std::string str_det_9 = "nd9_h7p7_2_fhc";
  //int det9_corr = cutOutDet_corr(  h_corr, det_9_lowBin,  det_9_highBin,  nBinsPerDet,  str_det_9, str_syst );
  int det9_err = getErrosFromCov( h_cov,  det_9_lowBin, det_9_highBin,  nBinsPerDet,  str_det_9 , str_syst );

  std::string str_det_10 = "nd9_h7p7_2_rhc";
  //int det10_corr = cutOutDet_corr(  h_corr, det_10_lowBin,  det_10_highBin,  nBinsPerDet,  str_det_10, str_syst );
  int det10_err = getErrosFromCov( h_cov,  det_10_lowBin, det_10_highBin,  nBinsPerDet,  str_det_10 , str_syst );

  std::string str_det_11 = "nd9_h7p7_3_fhc";
  //int det11_corr = cutOutDet_corr(  h_corr, det_11_lowBin,  det_11_highBin,  nBinsPerDet,  str_det_11, str_syst );
  int det11_err = getErrosFromCov( h_cov,  det_11_lowBin, det_11_highBin,  nBinsPerDet,  str_det_11 , str_syst );

  std::string str_det_12 = "nd9_h7p7_3_rhc";
  //int det12_corr = cutOutDet_corr(  h_corr, det_12_lowBin,  det_12_highBin,  nBinsPerDet,  str_det_12, str_syst );
  int det12_err = getErrosFromCov( h_cov,  det_12_lowBin, det_12_highBin,  nBinsPerDet,  str_det_12 , str_syst );

  std::string str_det_13 = "nd9_h7p7_4_fhc";
  //int det13_corr = cutOutDet_corr(  h_corr, det_13_lowBin,  det_13_highBin,  nBinsPerDet,  str_det_13, str_syst );
  int det13_err = getErrosFromCov( h_cov,  det_13_lowBin, det_13_highBin,  nBinsPerDet,  str_det_13 , str_syst );

  std::string str_det_14 = "nd9_h7p7_4_rhc";
  //int det14_corr = cutOutDet_corr(  h_corr, det_14_lowBin,  det_14_highBin,  nBinsPerDet,  str_det_14, str_syst );
  int det14_err = getErrosFromCov( h_cov,  det_14_lowBin, det_14_highBin,  nBinsPerDet,  str_det_14 , str_syst );

  std::string str_det_15 = "nd9_h7p7_5_fhc";
  //int det15_corr = cutOutDet_corr(  h_corr, det_15_lowBin,  det_15_highBin,  nBinsPerDet,  str_det_15, str_syst );
  int det15_err = getErrosFromCov( h_cov,  det_15_lowBin, det_15_highBin,  nBinsPerDet,  str_det_15 , str_syst );

  std::string str_det_16 = "nd9_h7p7_5_rhc";
  //int det16_corr = cutOutDet_corr(  h_corr, det_16_lowBin,  det_16_highBin,  nBinsPerDet,  str_det_16, str_syst );
  int det16_err = getErrosFromCov( h_cov,  det_16_lowBin, det_16_highBin,  nBinsPerDet,  str_det_16 , str_syst );

  std::string str_det_17 = "nd9_h7p7_6_fhc";
  //int det17_corr = cutOutDet_corr(  h_corr, det_17_lowBin,  det_17_highBin,  nBinsPerDet,  str_det_17, str_syst );
  int det17_err = getErrosFromCov( h_cov,  det_17_lowBin, det_17_highBin,  nBinsPerDet,  str_det_17 , str_syst );

  std::string str_det_18 = "nd9_h7p7_6_rhc";
  //int det18_corr = cutOutDet_corr(  h_corr, det_18_lowBin,  det_18_highBin,  nBinsPerDet,  str_det_18, str_syst );
  int det18_err = getErrosFromCov( h_cov,  det_18_lowBin, det_18_highBin,  nBinsPerDet,  str_det_18 , str_syst );

  std::string str_det_19 = "nd9_h7p7_7_fhc";
  //int det19_corr = cutOutDet_corr(  h_corr, det_19_lowBin,  det_19_highBin,  nBinsPerDet,  str_det_19, str_syst );
  int det19_err = getErrosFromCov( h_cov,  det_19_lowBin, det_19_highBin,  nBinsPerDet,  str_det_19 , str_syst );

  std::string str_det_20 = "nd9_h7p7_7_rhc";
  //int det20_corr = cutOutDet_corr(  h_corr, det_20_lowBin,  det_20_highBin,  nBinsPerDet,  str_det_20, str_syst );
  int det20_err = getErrosFromCov( h_cov,  det_20_lowBin, det_20_highBin,  nBinsPerDet,  str_det_20 , str_syst );

  std::string str_det_21 = "2_hk2_fhc";
  //int det21_corr = cutOutDet_corr(  h_corr, det_21_lowBin,  det_21_highBin,  nBinsPerDet,  str_det_21, str_syst );
  int det21_err = getErrosFromCov( h_cov,  det_21_lowBin, det_21_highBin,  nBinsPerDet,  str_det_21 , str_syst );

  std::string str_det_22 = "2_hk2_rhc";
  //int det22_corr = cutOutDet_corr(  h_corr, det_22_lowBin,  det_22_highBin,  nBinsPerDet,  str_det_22, str_syst );
  int det22_err = getErrosFromCov( h_cov,  det_22_lowBin, det_22_highBin,  nBinsPerDet,  str_det_22 , str_syst );

  std::string str_det_23 = "3_hk3_fhc";
  //int det23_corr = cutOutDet_corr(  h_corr, det_23_lowBin,  det_23_highBin,  nBinsPerDet,  str_det_23, str_syst );
  int det23_err = getErrosFromCov( h_cov,  det_23_lowBin, det_23_highBin,  nBinsPerDet,  str_det_23 , str_syst );

  std::string str_det_24 = "3_hk3_rhc";
  //int det24_corr = cutOutDet_corr(  h_corr, det_24_lowBin,  det_24_highBin,  nBinsPerDet,  str_det_24, str_syst );
  int det24_err = getErrosFromCov( h_cov,  det_24_lowBin, det_24_highBin,  nBinsPerDet,  str_det_24 , str_syst );

  std::string str_det_25 = "4_hk4_fhc";
  //int det25_corr = cutOutDet_corr(  h_corr, det_25_lowBin,  det_25_highBin,  nBinsPerDet,  str_det_25, str_syst );
  int det25_err = getErrosFromCov( h_cov,  det_25_lowBin, det_25_highBin,  nBinsPerDet,  str_det_25 , str_syst );

  std::string str_det_26 = "4_hk4_rhc";
  //int det26_corr = cutOutDet_corr(  h_corr, det_26_lowBin,  det_26_highBin,  nBinsPerDet,  str_det_26, str_syst );
  int det26_err = getErrosFromCov( h_cov,  det_26_lowBin, det_26_highBin,  nBinsPerDet,  str_det_26 , str_syst );

  std::string str_det_27 = "5_hk5_fhc";
  //int det27_corr = cutOutDet_corr(  h_corr, det_27_lowBin,  det_27_highBin,  nBinsPerDet,  str_det_27, str_syst );
  int det27_err = getErrosFromCov( h_cov,  det_27_lowBin, det_27_highBin,  nBinsPerDet,  str_det_27 , str_syst );

  std::string str_det_28 = "5_hk5_rhc";
  //int det28_corr = cutOutDet_corr(  h_corr, det_28_lowBin,  det_28_highBin,  nBinsPerDet,  str_det_28, str_syst );
  int det28_err = getErrosFromCov( h_cov,  det_28_lowBin, det_28_highBin,  nBinsPerDet,  str_det_28 , str_syst );



exit();
//sk_nd5_nd2_nd9h7p7_hk2_hk3_hkk4_hkk5




/*

// ND280   bin 161 (when numbered from 1) up to and including bin 240
//new

// 161 240

//const int nBinsPerDet = 80;
const int nd5_lower = 161;
const int nd5_higher = 240;

  TH2D* h_corr_nd5_fhc = new TH2D("h_corr_nd5_fhc", "h_corr_nd5_fhc", nBinsPerDet, 0, nBinsPerDet, nBinsPerDet, 0, nBinsPerDet );

  for( int irow=0; irow<nBinsPerDet; irow++ ){
    for( int icol=0; icol<nBinsPerDet; icol++ ){

      double e_corr = h_corr->GetBinContent( nd5_lower + irow, nd5_lower + icol);
      //std::cout<<" irow="<<irow<<"  icol="<<icol << "    e_corr = " << e_corr  << std::endl;
      h_corr_nd5_fhc->SetBinContent( irow+1, icol+1, e_corr );
      
    }
  }




  TCanvas* c_corr_nd5_fhc = new TCanvas("c_corr_nd5_fhc", "c_corr_nd5_fhc", 1000, 1000);
  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);  // remove title
  gStyle->SetOptTitle(0); // remove stat box
  //double m = TMath::Max(h_corr_nd5_fhc->GetMaximum(),-h_corr_nd5_fhc->GetMinimum());
  //h_corr_nd5_fhc->GetZaxis()->SetRangeUser( min, max);
  //Int_t nb = 5000;
  h_corr_nd5_fhc->SetContour(nb);
  h_corr_nd5_fhc->Draw("colz");
  c_corr_nd5_fhc->SaveAs("corr_nd5_fhc.png");
  c_corr_nd5_fhc->SaveAs("corr_nd5_fhc.pdf");
  c_corr_nd5_fhc->SaveAs("corr_nd5_fhc.eps");

*/




exit();

  // loop over the covariance matrix diagonal elements
  // cov_ii = var_i = (sig_i)^2
  // so uncorrelated error,  sig_i = sqrt( var(i) ) = sqrt{ cov_ii )

//std::cout<<"debug 1" << std::endl;


/*


  double var_corr_nd5_fhc[ nBinsPerDet ];
  double err_corr_nd5_fhc[ nBinsPerDet ];

  for( int irow=0; irow<nBinsPerDet; irow++){

    // h_cov starts at bin1, array starts at element 0
    std::cout<<" h_cov ( " <<  irow + nd5_lower <<" ," <<  irow + nd5_lower  << " = " <<
      h_cov->GetBinContent( irow + nd5_lower, irow + nd5_lower ) << std::endl;
    
    var_corr_nd5_fhc[irow] = h_cov->GetBinContent( irow + nd5_lower, irow + nd5_lower );
    err_corr_nd5_fhc[irow] = sqrt( var_corr_nd5_fhc[irow] );    
  }

  const int nBinsFlav=20;

  double err_corr_nd5_fhc_numu[ nBinsFlav ];
  TH1D* h_err_corr_nd5_fhc_numu = new TH1D("h_err_corr_nd5_fhc_numu", "h_err_corr_nd5_fhc_numu", nBinsFlav, 0, nBinsFlav);

  for( int irow=0; irow<20; irow++ ){
    double err = err_corr_nd5_fhc[ 0 + irow ];
    err_corr_nd5_fhc_numu[irow] = err;
    h_err_corr_nd5_fhc_numu->SetBinContent( irow+1, err); 
  }
  std::cout<<"dddbug2" <<std::endl;

  double err_corr_nd5_fhc_anumu[ 20 ];
  TH1D* h_err_corr_nd5_fhc_anumu = new TH1D("h_err_corr_nd5_fhc_anumu", "h_err_corr_nd5_fhc_anumu", nBinsFlav, 0, nBinsFlav);
  for( int irow=0; irow<20; irow++ ){
    double err = err_corr_nd5_fhc[ 20 + irow ];
    err_corr_nd5_fhc_anumu[irow]=err;
    h_err_corr_nd5_fhc_anumu->SetBinContent( irow+1, err);
  }
  double err_corr_nd5_fhc_nue[ 20 ];
  TH1D* h_err_corr_nd5_fhc_nue = new TH1D("h_err_corr_nd5_fhc_nue", "h_err_corr_nd5_fhc_nue", nBinsFlav, 0, nBinsFlav);
  for( int irow=0; irow<20; irow++ ){
    double err = err_corr_nd5_fhc[ 40 + irow ];
    err_corr_nd5_fhc_nue[irow]=err;
    h_err_corr_nd5_fhc_nue->SetBinContent( irow+1, err);
  } 
  double err_corr_nd5_fhc_anue[ 20 ];
  TH1D* h_err_corr_nd5_fhc_anue = new TH1D("h_err_corr_nd5_fhc_anue", "h_err_corr_nd5_fhc_anue", nBinsFlav, 0, nBinsFlav);
  for( int irow=0; irow<20; irow++ ){
    double err = err_corr_nd5_fhc[ 60 + irow ];
    err_corr_nd5_fhc_anue[irow]=err;
    h_err_corr_nd5_fhc_anue->SetBinContent( irow+1, err);
  }

  TCanvas* c_err_nd5_fhc = new TCanvas("c_errr_nd5_fhc", "c_err_nd5_fhc", 1000, 1000);
  gStyle->SetLineWidth(2);
  h_err_corr_nd5_fhc_anue->SetLineColor(kCyan+1);
  h_err_corr_nd5_fhc_anue->SetLineWidth(2);
  h_err_corr_nd5_fhc_anue->Draw();
  h_err_corr_nd5_fhc_anue->GetYaxis()->SetRangeUser(0, 0.1); 
  h_err_corr_nd5_fhc_nue->SetLineColor(kBlue+1);
  h_err_corr_nd5_fhc_nue->Draw("SAME");
  h_err_corr_nd5_fhc_anumu->SetLineColor(kOrange+7);
  h_err_corr_nd5_fhc_anumu->Draw("SAME");
  h_err_corr_nd5_fhc_numu->SetLineColor(kRed+1);
  h_err_corr_nd5_fhc_numu->Draw("SAME");



*/
}


int what(){
  std::cout<<" aghhhh " << std::endl;
  return 4;
}






int cutOutDet_corr( TH2D* h_corr,  const int lowBin, const int highBin, const int nBinsPerDet, std::string str_det, std::string str_syst ){

  int lb=lowBin, hb=highBin;

  TH2D* h_corr_det = new TH2D("h_corr_det", "h_corr_det", nBinsPerDet, 0, nBinsPerDet, nBinsPerDet, 0, nBinsPerDet );

  std::cout<<" Retriving detector corr from full corr matrix " << std::endl;
  for( int irow=0; irow<nBinsPerDet; irow++ ){
    for( int icol=0; icol<nBinsPerDet; icol++ ){
      std::cout<<" inside function      h_corr->GetBinConent(2,2) = " <<  h_corr->GetBinContent(2,2) << std::endl;

     int row = irow + lb;
     int col = icol + lb;
     double e_corr = h_corr->GetBinContent( row, col);
     std::cout<<" row="<<row<< ", col=" << col << "    e_corr = " << e_corr  << std::endl;
     h_corr_det->SetBinContent( irow+1, icol+1, e_corr );
      
    }
  }


  TCanvas* c_corr_det = new TCanvas("c_corr_nd5_fhc", "c_corr_nd5_fhc", 1000, 1000);
  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);  // remove title
  gStyle->SetOptTitle(0); // remove stat box
  //double m = TMath::Max(h_corr_nd5_fhc->GetMaximum(),-h_corr_nd5_fhc->GetMinimum());
  //h_corr_nd5_fhc->GetZaxis()->SetRangeUser( min, max);
  Int_t nb = 5000;
  h_corr_det->SetContour(nb);
  h_corr_det->Draw("colz");


  
  std::string str_save_det_syst = str_det +"_"+ str_syst;

  std::string str_save_det_syst_png = str_det +"_"+ str_syst +".png";
  std::string str_save_det_syst_pdf = str_det +"_"+ str_syst +".pdf";
  std::string str_save_det_syst_eps = str_det +"_"+ str_syst +".eps";

  const char* save_det_syst_png = str_save_det_syst_png.c_str();
  const char* save_det_syst_pdf = str_save_det_syst_pdf.c_str();
  const char* save_det_syst_eps = str_save_det_syst_eps.c_str();

  c_corr_det->SaveAs(save_det_syst_png);
  c_corr_det->SaveAs(save_det_syst_pdf);
  c_corr_det->SaveAs(save_det_syst_eps);

std::cout<<" saving" << std::endl;

  delete h_corr_det;
  delete c_corr_det;

  return 0;

}




int getErrosFromCov( TH2D* h_cov,  const int lowBin, const int highBin, const int nBinsPerDet, std::string str_det, std::string str_syst ){

  int lb=lowBin, hb=highBin;

  //////// Retrieving the errors from diag of full cov ///////
  std::cout<<" --- Retrieving the errors from diag of full cov --- " << std::endl;
  std::cout<<""<< std::endl;
  std::cout<<" Det: " << str_det << ",  Syst: " << str_syst <<  std::endl;
  std::cout<<""<< std::endl;

  double var_det[ nBinsPerDet ];
  double err_corr[ nBinsPerDet ];


  // This includes overflow bin for each flavour  nBinsPerDet = 4 * 20  

  for( int irow=0; irow<nBinsPerDet; irow++){

    // h_cov starts at bin1, array starts at element 0
    std::cout<<" h_cov ( " <<  irow + lowBin <<" ," <<  irow + lowBin  << ") = " <<
      h_cov->GetBinContent( irow + lowBin, irow + lowBin ) << std::endl;
    
    var_det[irow] = h_cov->GetBinContent( irow + lowBin, irow + lowBin );
    err_corr[irow] = sqrt( var_det[irow] );    
    std::cout<< "Error = " << err_corr[irow] <<std::endl;
  }

  std::cout<<""<<std::endl;
  std::cout<<""<<std::endl;

  const int nBinsFlav=20;


    // bins 1-19 are Energy bins
    // bin 20  is overflow

    int nbins = 19;
   double bins[20] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 1.0, 1.2, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 5.0, 7.0, 10.0};



//  double err_corr_numu[ nBinsFlav ];
//  TH1D* h_err_corr_numu = new TH1D("h_err_corr_numu", "h_err_corr_numu", nBinsFlav, 0, nBinsFlav);
//
//  for( int irow=0; irow<20; irow++ ){
//    double err = err_corr_[ 0 + irow ];
//    err_corr_numu[irow] = err;
//    h_err_corr_numu->SetBinContent( irow+1, err); 
//  }
//  std::cout<<"dddbug2" <<std::endl;
//
//  double err_corr_anumu[ 20 ];
//  TH1D* h_err_corr_anumu = new TH1D("h_err_corr_anumu", "h_err_corr_anumu", nBinsFlav, 0, nBinsFlav);
//  for( int irow=0; irow<20; irow++ ){
//    double err = err_corr[ 20 + irow ];
//    err_corr_anumu[irow]=err;
//    h_err_corr_anumu->SetBinContent( irow+1, err);
//  }
//  double err_corr_nue[ 20 ];
//  TH1D* h_err_corr_nue = new TH1D("h_err_corr_nue", "h_err_corr_nue", nBinsFlav, 0, nBinsFlav);
//  for( int irow=0; irow<20; irow++ ){
//    double err = err_corr[ 40 + irow ];
//    err_corr_nue[irow]=err;
//    h_err_corr_nue->SetBinContent( irow+1, err);
//  } 
//  double err_corr_anue[ 20 ];
//  TH1D* h_err_corr_anue = new TH1D("h_err_corr_anue", "h_err_corr_anue", nBinsFlav, 0, nBinsFlav);
//  for( int irow=0; irow<20; irow++ ){
//    double err = err_corr_[ 60 + irow ];
//    err_corr_anue[irow]=err;
//    h_err_corr_anue->SetBinContent( irow+1, err);
//  }
//


  // Energy bins  1-19 [0-18]
  // Overflow bin 20   [19]

  // nBinsPerDet = 20* 40 = ( 19 +1 )*4

  // numu  [ 0-18]  [overflow 19]
  // anumu [20-38]  [overflow 39]
  // nue   [40-58]  [overflow 49]
  // anue  [60-78]  [overflow 79]


  std::string  str_hist_err_det = str_det +":  "+ str_syst;
  const char* ch_hist_err_det = str_hist_err_det.c_str();

//  double err_corr_numu[ nBinsFlav ];
  TH1D* h_err_corr_numu = new TH1D("h_err_corr_numu", ch_hist_err_det, nbins, bins);
  for( int irow=0; irow<19; irow++ ){  // not plotting overflow bin 20
    double err = err_corr[ 0 + irow ];
    std::cout<<" numu, bin = "<< irow + 1 << " Err = " << err << std::endl;
    //err_corr_numu[irow] = err;
    h_err_corr_numu->SetBinContent( irow+1, err); 
  }

//  std::string  str_hist_err_det_anumu = str_det +":  "+ str_syst +" - anti-numu";
//  const char* ch_hist_err_det_anumu = str_hist_err_det_anumu.c_str();
  double err_corr_anumu[ nBinsFlav ];
  TH1D* h_err_corr_anumu = new TH1D("h_err_corr_anumu", ch_hist_err_det, nbins, bins);
  for( int irow=0; irow<19; irow++ ){
    double err = err_corr[ 20 + irow ];
    err_corr_anumu[irow]=err;
    h_err_corr_anumu->SetBinContent( irow+1, err);
  }

//  std::string  str_hist_err_det_nue = str_det +":  "+ str_syst +" - nue";
//  const char* ch_hist_err_det_nue = str_hist_err_det_nue.c_str();
  double err_corr_nue[ nBinsFlav ];
  TH1D* h_err_corr_nue = new TH1D("h_err_corr_nue", ch_hist_err_det, nbins, bins);
  for( int irow=0; irow<19; irow++ ){
    double err = err_corr[ 40 + irow ];
    err_corr_nue[irow]=err;
    h_err_corr_nue->SetBinContent( irow+1, err);
  } 

//  std::string  str_hist_err_det_anue = str_det +":  "+ str_syst +" - anti-nue";
//  const char* ch_hist_err_det_anue = str_hist_err_det_anue.c_str();
  double err_corr_anue[ nBinsFlav ];
  TH1D* h_err_corr_anue = new TH1D("h_err_corr_anue", ch_hist_err_det, nbins, bins);
  for( int irow=0; irow<19; irow++ ){
    double err = err_corr[ 60 + irow ];
    err_corr_anue[irow]=err;
    h_err_corr_anue->SetBinContent( irow+1, err);
  }





  double max=1.0;

  if( str_syst=="alttert") max = 0.3;
  if( str_syst=="na61")    max = 0.4;
  if( str_syst=="bmpt")    max = 0.5;
  if( str_syst=="harp")    max = 0.1;
  if( str_syst=="oaax")    max = 1.0;
  if( str_syst=="oaay")    max = 1.0;
  if( str_syst=="pbeamx")    max = 0.4;
  if( str_syst=="pbeamy")    max = 0.4;
  if( str_syst=="prodx")    max = 0.2;
  if( str_syst=="snextbar")    max = 0.1;
  if( str_syst=="snleadbar")    max = 0.2;
  if( str_syst=="snmult")    max = 0.1;




//  if( h_err_corr_anue->GetMaximum() >  max)  max = h_err_corr_anue->GetMaximum() ;
//  if( h_err_corr_nue->GetMaximum() >  max)   max = h_err_corr_nue->GetMaximum() ;
//  if( h_err_corr_anumu->GetMaximum() >  max) max = h_err_corr_numu->GetMaximum() ;
//  if( h_err_corr_anumu->GetMaximum() >  max) max = h_err_corr_anumu->GetMaximum() ;


  TCanvas* c_err =  new TCanvas("c_err", "c_err", 1000, 1000);
  gStyle->SetLineWidth(2);
  gStyle->SetOptStat(0);

  h_err_corr_anue->SetLineColor(kCyan+1);
  h_err_corr_anue->SetLineWidth(3);
  h_err_corr_anue->GetYaxis()->SetTitle("Fractional Error");
  h_err_corr_anue->GetXaxis()->SetTitle("Enu (GeV)");
  h_err_corr_anue->GetXaxis()->SetTitleOffset(1.4);
  h_err_corr_anue->GetYaxis()->SetTitleOffset(1.6);
  h_err_corr_anue->Draw();
  h_err_corr_anue->GetYaxis()->SetRangeUser(0, max); 

  h_err_corr_nue->SetLineColor(kBlue+1);
  h_err_corr_nue->SetLineWidth(3);
//  h_err_corr_nue->GetYaxis()->SetTitle("Fractional Error");
//  h_err_corr_nue->GetXaxis()->SetTitle("Enu (GeV)");
  h_err_corr_nue->Draw("SAME");

  h_err_corr_anumu->SetLineColor(kOrange+7);
  h_err_corr_anumu->SetLineWidth(3);
  h_err_corr_anumu->Draw("SAME");

  h_err_corr_numu->SetLineColor(kRed+1);
  h_err_corr_numu->SetLineWidth(3);
  h_err_corr_numu->Draw("SAME");
//  h_err_corr_numu->GetYaxis()->SetTitle("Fractional Error");
//  h_err_corr_numu->GetXaxis()->SetTitle("Enu (GeV)");
 


  
  //std::string str_save_det_syst = str_det +"_"+ str_syst +"_errs";

  std::string str_save_det_syst_png = "./"+ str_det +"_"+ str_syst +"_errs.png";
  std::string str_save_det_syst_pdf = "./"+ str_det +"_"+ str_syst +"_errs.pdf";
  std::string str_save_det_syst_eps = "./"+ str_det +"_"+ str_syst +"_errs.eps";

  const char* save_det_syst_png = str_save_det_syst_png.c_str();
  const char* save_det_syst_pdf = str_save_det_syst_pdf.c_str();
  const char* save_det_syst_eps = str_save_det_syst_eps.c_str();

  std::cout<<"About to save error plots " << std::endl;

  c_err->SaveAs(save_det_syst_png);
  c_err->SaveAs(save_det_syst_pdf);
  c_err->SaveAs(save_det_syst_eps);

  std::cout<<"Should have now error plots " << std::endl;

  std::cout<<"-------------------------------" << std::endl;

  delete c_err;
  delete h_err_corr_anue;
  delete h_err_corr_anue;
  delete h_err_corr_anue;
  delete h_err_corr_anue;

  return 0;
}

