# This is the Octopress Gravatar plugin
#
# Place this file in your plugin directory and you have an _highlight_ keyword to create a span with fluo class containing your text
#
# Usage: {% highlight this is a great piece of wisdom %}, this is not.
#

module Jekyll
  class Highlight < Liquid::Block
    @text = ""

    def initialize(tagname, text, tokens)
        super
    end

    def render(context)
        @text = "<pre class=\"prettyprint linenums\">"
        @text += super
        @text += "</pre>"
    end
  end
end
Liquid::Template.register_tag('highlight', Jekyll::Highlight)
