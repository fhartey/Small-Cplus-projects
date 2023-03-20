# Object Diff

### How To Run
- JavaScript
  - `npm install`
  - `npm test objectdiff.js`
- Python
  - `python3 objectdiff.py`

### Problem
This task should proceed in 4 phases. 

1. The first should produce the diff provided in the task description. essentially focused on diff for a one layered object.
1. The second phase is about traversing to a single layer of depth.
The following test objects should be provided to the candidate after they have a working function for phase 1.

```javascript
before = {
        "app.js": [516, "javascript", "Oct 12 09:04"],
        "main": {
            "__init__.js":[0, "javascript", "Oct 15 10:36"],
            "README.md":[464, "markdown", "Oct 15 11:05"],
            "test.js": [2418, "javascript", "Oct 15 10:20"],
            "urls.js": [503, "javascript", "Oct 15 10:14"],
            "views.js":[1230, "javascript", "Oct 15 10:20"]
        },
        "README.md": [1516, "markdown", "Oct 15 11:06"],
        "package.json": [347, "json", "Oct 9 13:10"]
}

after = {
        "app.js": [516, "javascript", "Oct 12 09:04"],
        "Dockerfile": [2090, "Plain Text", "Oct 13 15:12"],
        "main": {
            "__init__.js":[0, "javascript", "Oct 15 10:36"],
            "MAIN.md":[464, "markdown", "Oct 16 11:05"],
            "models.js":[3780, "javascript", "Oct 16 16:22"],
            "urls.js": [503, "javascript", "Oct 15 10:14"],
        },
        "README.md": [1516, "markdown", "Oct 15 11:06"],
        "package.json": [347, "json", "Oct 9 13:10"]
}
```

They should produce a diff like this.

```javascript
object_diff = [
    ['-', 'main/README.md'],
    ['-', 'main/test.js'],
    ['-', 'main/views.js'],
    ['+', 'Dockerfile'],
    ['+', 'main/MAIN.md'],
    ['+', 'main/models.js'],
]
```

3. The third phase should deal with doubly nested objects. For strong candidates the solution provided for phase 2 should also suffice for phase three.

```javascript
before = {
        "main": {
            "test":{
                "__init__.js":[0, "javascript", "Oct 17 08:02"],
                "test.js": [2418, "javascript", "Oct 17 08:03"],
                "test_data.json": [452216, "json", "Oct 17 18:35"]
            },
            "__init__.js":[0, "javascript", "Oct 15 10:36"],
            "README.md":[464, "markdown", "Oct 15 11:05"],
            "urls.js": [503, "javascript", "Oct 15 10:14"],
            "views.js":[1230, "javascript", "Oct 15 10:20"]
        },
        "app.js": [516, "javascript", "Oct 12 09:04"],
        "README.md": [1516, "markdown", "Oct 15 11:06"],
        "package.json": [347, "json", "Oct 9 13:10"]
}

after = {
        "main": {
            "test":{
                "__init__.js":[0, "javascript", "Oct 17 08:02"],
                "test.js": [2418, "javascript", "Oct 17 08:03"],
                "fixtures.json": [452216, "json", "Oct 17 18:35"]
            },
            "documentation": {
                "MAIN.md":[464, "markdown", "Oct 17 12:05"],
            },
            "__init__.js":[0, "javascript", "Oct 15 10:36"],
            "models.js":[3780, "javascript", "Oct 16 16:22"],
            "urls.js": [503, "javascript", "Oct 15 10:14"],
        },
        "app.js": [516, "javascript", "Oct 12 09:04"],
        "Dockerfile": [2090, "Plain Text", "Oct 13 15:12"],
        "README.md": [1516, "markdown", "Oct 15 11:06"],
        "package.json": [347, "json", "Oct 9 13:10"]
}

object_diff = [
    ['-', 'main/test/test_data.json'],
    ['-', 'main/README.md'],
    ['-', 'main/views.js'],
    ['+', 'main/test/fixtures.json'],
    ['+', 'main/documentation/MAIN.md'],
    ['+', 'main/models.js'],
    ['+', 'Dockerfile']
]
```

Finally for the fourth phase, we ask them to consider how they would deal with the the tuple containing the file details. how do we report differences in this tuple with reference to the parent file?

ex.

``` javascript
object_diff = [
    ['-', 'main/test/test_data.json', [452216, "json", "Oct 17 18:35"]],
    ['-', 'main/README.md', [464, "markdown", "Oct 15 11:05"]],
    ['-', 'main/views.js', [1230, "javascript", "Oct 15 10:20"]],
    ['+', 'main/test/fixtures.json', [452216, "json", "Oct 17 18:35"]],
    ['+', 'main/documentation/MAIN.md', [464, "markdown", "Oct 17 12:05"]],
    ['+', 'main/models.js', [3780, "javascript", "Oct 16 16:22"]],
    ['+', 'Dockerfile', [2090, "Plain Text", "Oct 13 15:12"]]
]
```
