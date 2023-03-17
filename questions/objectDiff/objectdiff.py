from unittest import TestCase, main as unitTestMain


def diff(before, after):
    # write your implementation here!
    raise NotImplementedError()


class FileSystemObjectDifferTestCase(TestCase):

    def test_diff_shows_added_and_removed_elements(self):
        before = {
            "hello_world.py": (516, "Python", "Oct 12 09:04"),
            "README.md": (1516, "Markdown", "Oct 12 09:06"),
            "requirements.txt": (347, "Plain Text", "Oct 9 13:10")
        }

        after = {
            "app.py": (516, "Python", "Oct 13 15:12"),
            "Dockerfile": (2090, "Plain Text", "Oct 13 15:12"),
            "README.md": (1516, "Markdown", "Oct 12 09:06"),
            "requirements.txt": (347, "Plain Text", "Oct 9 13:10")
        }

        result = diff(before, after)

        expected_result = [
            ['-', 'hello_world.py'],
            ['+', 'app.py'],
            ['+', 'Dockerfile']
        ]

        self.assertEqual(expected_result, result)

if __name__ == '__main__':
    unitTestMain()
