{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 12; //number of data points
   Double_t x[n]  ={-0.54,
0.50,

-0.46,
0.42,

-0.37,
0.33,

-0.28,
0.24,

-0.19,
0.15,

-0.11,
0.07,




}; //x values
  
   Double_t y[n] = {0.164060949687467,
0.160570291183478,

0.345200550852942,
0.345200550852942,

0.848845496024803,
0.988528932079517,

3.43129892516752,
5.56163143320992,

15.73313824448,
26.6874175769751,

21.0558229832204,
22.2003397591613,




}; //y values

   
   Double_t ex[n] ={0.02,0.02,

0.02,

0.02,

0.02,

0.02,

0.02,

0.02,

0.02,

0.02,

0.02,

0.02,







}; //error of x values
   
   Double_t ey[n] ={0.023930749031299,
0.023674797832454,

0.039086265590485,
0.039086265590485,

0.095502579733306,
0.103061265525513,

0.236220359748067,
0.300738584966944,

0.414316976334881,
0.539607931670244,

0.339565882689635,
0.348672542707389,


}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";Angle(Degrees);Count");
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("AP");
   
   TF1 *f = new TF1("f","1/([0]*pow(sin(x/2), 4))");
   f->SetLineColor(kRed+0);
   f->SetParameters(1, 1);
   gr->Fit("f");
   gStyle->SetOptStat(111110);
   gStyle->SetOptFit(1111);


   return c1;
}
