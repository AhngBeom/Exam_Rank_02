# Exam_Rank_02

## PFT_EXAM

Make sure your exam's file is named "ft_printf.c" and run :

    gcc -c ft_printf.c && ar rc libftprintf.a ft_printf.o

Now, still in your exam repository, run :
   
    git clone https://github.com/gavinfielder/pft.git pft_exam && echo "pft_exam/" >> .gitignore && cd pft_exam && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_EXAM.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
