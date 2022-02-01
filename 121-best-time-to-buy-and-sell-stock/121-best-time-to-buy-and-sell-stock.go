func maxProfit(prices []int) int {
    minPrice := prices[0]
    ans := 0
    for _,value := range prices {
        if(value - minPrice > ans){
            ans = value - minPrice
        }
        if(value < minPrice){
            minPrice = value
        }
    }
    return ans
}