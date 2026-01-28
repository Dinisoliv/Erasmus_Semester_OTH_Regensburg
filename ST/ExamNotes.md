# Probability — Ultra-Compact Exam Triggers

## Discrete Random Variables
Mean:
E(X) = Σ x·P(X=x)

Variance:
Var(X) = E(X²) − [E(X)]²

Std Dev:
σ = √Var(X)

---

## Functions of RVs (Y = Φ(X))
Distribution:
P(Y=y) = P(X such that Φ(X)=y)

Expectation:
E(Φ(X)) = Σ Φ(x)·P(X=x)

---

## Linear Properties
E(X+Y) = E(X) + E(Y)  
E(aX+b) = aE(X)+b  

Var(aX+b) = a²Var(X)

---

## Standardization
Z = (X − μ) / σ  
⇒ E(Z)=0, Var(Z)=1

---

## Joint Distributions
Joint pmf:
h(x,y) = P(X=x, Y=y)

Marginals:
f(x)=Σ h(x,y)  
g(y)=Σ h(x,y)

---

## Independence (Discrete)
X ⟂ Y ⇔ h(x,y)=f(x)g(y)

Covariance:
cov(X,Y)=E(XY)−E(X)E(Y)

Independent ⇒ cov(X,Y)=0

---

## Sums of RVs
Z = X + Y

E(Z)=E(X)+E(Y)

Var(Z)=Var(X)+Var(Y)+2cov(X,Y)

If independent:
Var(Z)=Var(X)+Var(Y)

---

## Binomial Distribution
X ~ Bin(n,p)

P(X=k)=C(n,k)pᵏ(1−p)ⁿ⁻ᵏ

Mean:
E(X)=np

Variance:
Var(X)=np(1−p)

“At least one”:
1 − P(0)

---

## Sample with Replacement
Trials independent  
⇒ Binomial model applies

---

## Normal Distribution
X ~ N(μ,σ)

Standardize:
Z = (X−μ)/σ

Use normal table with Z

---

## Empirical Rule (Quick)
±1σ → ~68%  
±2σ → ~95%  
±3σ → ~99.7%

---

## Normal → Counts
Expected number:
N · P(interval)

---

## Exam Auto-Triggers
“Given that …” → Bayes  
“Total / overall” → Law of Total Probability  
“Sum of RVs” → Expectation linearity  
“Independent?” → Check joint = product  
“Between / less than” → Z-scores
