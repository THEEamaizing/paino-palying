pragma solidity 0.8.26;

contract sample {

uint256 myPen;


    function store(uint256 _myPen) public {
        myPen = _myPen;
              
}

function retreve() public view returns (uint256) {
    return myPen;
}

}