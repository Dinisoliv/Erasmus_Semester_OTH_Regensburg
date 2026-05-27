# Probability & Random Variables --- Quick Exam Notes

## 1. Law of Total Probability

Used when an event depends on several **disjoint cases**.

P(A) = Σ P(A \| Bᵢ) P(Bᵢ)

Typical use: voting problems, population groups, class-based problems.

------------------------------------------------------------------------

## 2. Bayes' Theorem

Used to **reverse conditional probabilities**.

P(Bⱼ \| A) = \[P(A \| Bⱼ) P(Bⱼ)\] / Σ P(A \| Bᵢ) P(Bᵢ)

Typical use: given that someone voted / is tall → find group
probability.

------------------------------------------------------------------------

## 3. Independent Events

Events A and B are independent if:

P(A ∩ B) = P(A) P(B)

Equivalent: P(A \| B) = P(A)

------------------------------------------------------------------------

## 4. Independent Repeated Trials

If trials are independent: - Multiply probabilities for ordered
outcomes - Use combinations when order does not matter

------------------------------------------------------------------------

## 5. Binomial Distribution

Conditions: - Fixed number of trials n - Two outcomes - Constant
probability p

P(X = k) = C(n, k) p\^k (1 − p)\^(n − k)

Mean: E(X) = np\
Variance: Var(X) = np(1 − p)

------------------------------------------------------------------------

## 6. Sample Space Strategy

1.  Write the sample space
2.  Assign probabilities
3.  Define events

Used in coin tosses, dice, children problems.

------------------------------------------------------------------------

## 7. Random Variables

Expectation: E(X) = Σ x P(X = x)

Variance: Var(X) = E(X²) − \[E(X)\]²

Standard deviation: σ = √Var(X)

------------------------------------------------------------------------

## 8. Linear Transformations

If Y = aX + b:

E(Y) = aE(X) + b\
Var(Y) = a² Var(X)

------------------------------------------------------------------------

## 9. Joint Distributions

If X and Y are independent:

h(x, y) = f(x) g(y)

Covariance: cov(X, Y) = E(XY) − E(X)E(Y)

If independent → cov(X, Y) = 0

------------------------------------------------------------------------

## 10. Standardization

Z = (X − μ) / σ

Result: E(Z) = 0\
Var(Z) = 1

------------------------------------------------------------------------

## 11. Normal Distribution

X \~ N(μ, σ)

Z-score: Z = (X − μ) / σ

Rules: - 68% within μ ± σ - 95% within μ ± 2σ - 99.7% within μ ± 3σ

------------------------------------------------------------------------

## 12. Expected Number of Successes

E = np

Probability that expectation occurs: P(X = np) using binomial formula

------------------------------------------------------------------------

## Exam Tips

-   Define events clearly
-   Check independence before multiplying
-   Use Bayes only to reverse conditionals
-   Write formulas before substituting numbers
