-- 코드를 입력하세요
SELECT CART_ID
FROM (SELECT *
     FROM CART_PRODUCTS
     WHERE NAME IN('Milk','Yogurt')
     GROUP BY NAME,CART_ID
     ) AS A
GROUP BY CART_ID
HAVING COUNT(CART_ID) >= 2
ORDER BY CART_ID