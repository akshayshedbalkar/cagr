# cagr
Calculate future value of an investment

The rate of return does not always reflect what you might get out of a stock or fund. Costs and inflation eat into your return, leading to a more realistic future. 

In *cagr*, first the annual rate of return is calculated. Then the future value of the investement after a number of years is shown. The result already deducts taxes and fees and adjusts the result for inflation. 

In addition the amount of money lost due to taxes and fees is printed. 

Some assumptions are made in the code for fixed costs which are:
1. Taxes: capital gains tax is set at 25%. This is the rate in Germany

2. Inflation: set at 3% which is a realistic value in Germany over past few years

3. Fees: This one is harder to assume. Index funds can have fees as low as 0.01%, while actively manages funds can go as high as 2%. Stocks have buying, selling and exchange fees. Further, many banks/ brokers charge for the account itself. This charge might be waived if regular transactions are made. 
A value of 0.2% is set here. This is a reasonable value considering all these factors. 

The assumptions can be changed in main.c.
