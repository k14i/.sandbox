#!/usr/bin/env python

import commands as cmd
import sys
import os


ANY_BUILD_VERSION = '20151201'


def version():
    git_revision = None
    out = cmd.getoutput("GIT_DIR=\"{ANY_BUILD_INSTALL_PREFIX:s}/.git\" \
        git remote -v 2>/dev/null | grep -q /any-build;".format(**locals()))
    if out is True:
        git_revision = cmd.getoutput("GIT_DIR=\"{ANY_BUILD_INSTALL_PREFIX:s}/.git\" \
            git describe --tags HEAD 2>/dev/null || true".format(**locals()))
    if git_revision is not None:
        print("any-build %s" % git_revision)
    elif ANY_BUILD_VERSION is not None:
        print("any-build %s" % ANY_BUILD_VERSION)
    else:
        raise
    return git_revision


def usage():
    return True


def list_definitions():
    return True


ANY_BUILD_INSTALL_PREFIX = os.path.abspath(sys.argv[0])

try:
    target = ANY_BUILD_ROOT
except NameError:
    target = ANY_BUILD_INSTALL_PREFIX + '/share/any-build'

ANY_BUILD_DEFINITIONS = [ANY_BUILD_DEFINITIONS, target]

if __name__ == '__main__':
    try:
        if len(sys.argv) == 1:
            raise ValueError

        action = str(sys.argv[1]).strip().lower()

        if action in {'h', 'help'}:
            version()
            usage()
        elif action in {'d', 'definitions'}:
            list_definitions()
            sys.exit(0)
        elif action in {'k', 'keep'}:
            KEEP_BUILD_PATH = True
        elif action in {'v', 'verbose'}:
            VERBOSE = True
        elif action in {'p', 'patch'}:
            HAS_PATCH = True
        elif action in {'4', 'ipv4'}:
            IPV4 = True
        elif action in {'6', 'ipv6'}:
            IPV6 = True
        elif action in {'V', 'version'}:
            version()
            sys.exit(0)

    except (SystemExit):
        pass

    except (ValueError):
        #echo_failure()
        print >> sys.stderr, "Usage: %s" % sys.argv[0]
        sys.exit(2)

    except:
        exc_type, value = sys.exc_info()[:2]
        #echo_failure()
        print >> sys.stderr, "ERROR: %s (%s)" % (exc_type, value)
        sys.exit(1)


if len(sys.argv) is 2:
    usage()
    exit(1)

DEFINITION_PATH = sys.argv[0]
if len(DEFINITION_PATH) is 0:
    usage()
    exit(1)
elif os.path.exists(DEFINITION_PATH) is False:
    for definition_dir in ANY_BUILD_DEFINITIONS:
        if os.path.exists(definition_dir + '/' + DEFINITION_PATH):
            DEFINITION_PATH = definition_dir + '/' + DEFINITION_PATH
            break

    if os.path.exists(DEFINITION_PATH) is False:
        print("any-build: definition not found: %(DEFINITION_PATH)s" % locals())
        exit(2)

