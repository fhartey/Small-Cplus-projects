const Mocha = require('mocha')
const { expect } = require('chai')
const mocha = new Mocha()
mocha.suite.emit('pre-require', this, 'solution', mocha)

const diff = (before, after) => {
  // write your implementation here!
  throw "Not implemented";
}


describe('Object differ test case', () => {

  it('should show diff for added and removed elements', () => {
    const before = {
      "hello_world.js": [516, "javascript", "Oct 12 09:04"],
      "README.md": [1516, "markdown", "Oct 12 09:06"],
      "package.json": [347, "json", "Oct 9 13:10"]
    };

    const after  = {
      "app.js": [516, "javascript", "Oct 13 15:12"],
      "Dockerfile": [2090, "plaintext", "Oct 13 15:12"],
      "README.md": [1516, "markdown", "Oct 12 09:06"],
      "package.json": [347, "json", "Oct 9 13:10"]
    };

    const result = diff(before, after);

    const expectedResult = [
        ['-', 'hello_world.js'],
        ['+', 'app.js'],
        ['+', 'Dockerfile']
    ];

    expect(result).to.deep.equal(expectedResult);
  });

})

mocha.run()
