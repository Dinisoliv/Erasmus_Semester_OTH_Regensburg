# Probability & Random Variables — Quick Exam Notes

[ChatGPT](https://chatgpt.com/c/697a4715-8f50-8330-9f8b-ad67be68665a)

## 1. Law of Total Probability

Used when an event depends on several **disjoint cases**.

If (B_1, B_2, \dots, B_n) form a partition of the sample space:

[ P(A) = \sum_i P(A \mid B_i) P(B_i) ]

**Typical use:** voting problems, population groups, classes (freshman/sophomore/etc.).

---

## 2. Bayes’ Theorem

Used to **reverse conditional probabilities**.

[ P(B_j \mid A) = \frac{P(A \mid B_j) P(B_j)}{\sum_i P(A \mid B_i) P(B_i)} ]

**Typical use:** given someone voted / is tall / is NY resident → find group probability.

---

## 3. Independent Events

Events (A) and (B) are independent if:

[ P(A \cap B) = P(A) P(B) ]

Equivalent:
[ P(A \mid B) = P(A) ]

**Tip:** Always check independence — don’t assume it.

---

## 4. Independent Repeated Trials

If trials are independent and probabilities are constant:

* Multiply probabilities for sequences
* Use combinations when order doesn’t matter

---

## 5. Binomial Distribution

Used when:

* Fixed number of trials (n)
* Two outcomes (success/failure)
* Constant probability (p)

[ P(X = k) = \binom{n}{k} p^k (1-p)^{n-k} ]

Mean:
[ E(X) = np ]

Variance:
[ Var(X) = np(1-p) ]

---

## 6. Sample Space Strategy

1. Write the sample space clearly
2. Assign probabilities
3. Define events explicitly

**Used in:** coin tosses, dice, family children problems.

---

## 7. Random Variables

A random variable assigns numbers to outcomes.

### Expectation

[ E(X) = \sum x P(X=x) ]

### Variance

[ Var(X) = E(X^2) - [E(X)]^2 ]

Standard deviation:
[ \sigma = \sqrt{Var(X)} ]

---

## 8. Linear Transformations

If (Y = aX + b):

* (E(Y) = aE(X) + b)
* (Var(Y) = a^2 Var(X))

---

## 9. Joint Distributions

For independent (X) and (Y):

[ h(x,y) = f(x) g(y) ]

Covariance:
[ cov(X,Y) = E(XY) - E(X)E(Y) ]

If independent → (cov(X,Y)=0)

---

## 10. Standardization

[ Z = \frac{X - \mu}{\sigma} ]

Result:

* (E(Z)=0)
* (Var(Z)=1)

---

## 11. Normal Distribution

[ X \sim N(\mu, \sigma) ]

Convert to Z-score:
[ Z = \frac{X-\mu}{\sigma} ]

Use symmetry:

* 68% in ([\mu \pm \sigma])
* 95% in ([\mu \pm 2\sigma])
* 99.7% in ([\mu \pm 3\sigma])

---

## 12. Counting Expected Numbers

Expected number of successes:
[ E = np ]

Probability that expectation occurs:
[ P(X = np) ] (use binomial formula)

---

## Exam Tips

* Always define events clearly
* Check independence before multiplying
* Use Bayes only when reversing conditionals
* Write formulas first, then substitute numbers
* Keep calculations clean and structured
