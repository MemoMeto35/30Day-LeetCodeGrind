// you need to find the indices of two numbers in an array that sum up to a specific number. 

const arr = [1, 3, 5, 9, 2];
const targetToFind = 14; 

const findTwoSum = function(nums, target) {
  for(let p1 = 0; p1 < nums.length; p1++){
    const numberToFind = target - nums[p1];
    for(let p2 = p1 + 1; p2 < nums.length; p2++){
      if(numberToFind === nums[p2]){
        return [p1, p2];
      }
    }
  }
  return null; 
};
console.log(findTwoSum(arr, TargetToFind));
