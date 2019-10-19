{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 14; //number of data points
   Double_t x[n]  ={0.6,
1.3,
2,
2.6,
3.3,
4.4,
4.6,
5.2,
6,
6.7,
7.3,
7.9,
8.5,
9.3,

}; //x values
  
   Double_t y[n] = {1,
2,
3,
4,
5,
6,
7,
8,
9,
10,
11,
12,
13,
14,

}; //y values

   
   Double_t ex[n] ={0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,
0.14142135623731,

}; //error of x values
   
   Double_t ey[n] ={
}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";distance from the direct laser beam;fringe number");
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("AP");
   
   TF1 *f = new TF1("f","x*[1]+[0]");
   f->SetLineColor(kRed+0);
   f->SetParameters(1, 1);
   gr->Fit("f");
   gStyle->SetOptStat(111110);
   gStyle->SetOptFit(1111);


   return c1;
}
