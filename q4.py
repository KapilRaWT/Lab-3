def compute_gross_salary(basic, grade):
    hra = 0.20 * basic
    da = 0.50 * basic
    
    if grade == 'A':
        allow = 1700
    elif grade == 'B':
        allow = 1500
    elif grade == 'C':
        allow = 1300
    else:
        allow = 0
    
    pf = 0.11 * basic
    
    gross_salary = basic + hra + da + allow - pf
    return gross_salary


basic_salary_A = 10000
grade_A = 'A'
gross_salary_A = compute_gross_salary(basic_salary_A, grade_A)
print(f"Gross Salary (Grade A): {gross_salary_A:.2f}")

basic_salary_B = 4567
grade_B = 'B'
gross_salary_B = compute_gross_salary(basic_salary_B, grade_B)
print(f"Gross Salary (Grade B): {gross_salary_B:.2f}")

