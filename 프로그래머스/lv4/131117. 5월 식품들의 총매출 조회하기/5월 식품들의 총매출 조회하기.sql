-- 코드를 입력하세요
SELECT A.PRODUCT_ID, B.PRODUCT_NAME, SUM(B.PRICE * A.AMOUNT) AS TOTAL_SALES
FROM FOOD_ORDER A 
JOIN FOOD_PRODUCT B ON A.PRODUCT_ID = B.PRODUCT_ID
WHERE SUBSTR(A.PRODUCE_DATE, 1, 7) = "2022-05"
GROUP BY B.PRODUCT_ID
ORDER BY TOTAL_SALES DESC, B.PRODUCT_ID

